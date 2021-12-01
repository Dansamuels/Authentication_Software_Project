#include "person.h"
#include <iostream>
#include <string>
#include <fstream>


//This function encrypts the user's password
unsigned int Person::RSHash(const char* str, unsigned int length)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;
    unsigned int i    = 0;

    for(i=0; i< length; ++str,++i)
    {
        hash = hash * a + (*str);
        a    = a * b;
    }
    return hash;
}

// This method stores the user's
// information in file person.txt
void Person::getInfo()
{
    std::ofstream person_file("person.txt", ios::app);
    cout << "What is your name: ";
    cin >> name;
    person_file << name << endl;
    cout << "Create a password: ";
    cin >> password;
    person_file <<RSHash(password.c_str(), password.length()) << endl; 
    cout << "What is your age: ";
    cin >> age;
    person_file << age<< endl;
    cout << "Where were you born: ";
    cin >> place_of_birth;
    person_file << place_of_birth << endl;
    cout << "How many friends do you have: ";
    cin >> no_of_friends;
    person_file << no_of_friends << endl;
    cout << "What are their names: ";
    cin >> friends;
    person_file << friends << endl;
    cout << endl;
    person_file.close();
}

// This function display the users information
// to the console
void Person::enteredInfo()
{   

    cout << "Welcome " << name << "! " << endl;
    cout << "Your age is " << age << endl;
    cout << "You were born in " << place_of_birth << endl;
    cout << "You have "<< no_of_friends << "  and they are " << endl;
    cout << friends  << " born in " << endl;
}



//This method checks that the user's name
//matches their password
void Person::get_name_password()
{
    int pword,encrypted_pword;
    string n;
    std::ifstream person_file2("person.txt",ios::in);
    cout <<"Enter your name: "; cin >> name;
    cout <<"Enter your password: "; cin >> password;
    // stores user input in a string
    RSHash(password.c_str(), password.length()); 
    // passes the user's password into the function
    while(!person_file2.eof())
    {     
        getline(person_file2,n) && person_file2 >> pword;
          if( name == n && RSHash(password.c_str(), password.length()) == pword)
            { 
                cout << endl;
                cout << "Welcome " << name << "! " << endl;
                cout << "Your age is "; person_file2 >> age; cout << age << endl;
                cout << "You were born in "; person_file2 >> place_of_birth; cout << place_of_birth << endl;
                cout << "You have "; person_file2 >> no_of_friends; cout << no_of_friends << " friends whoes names are\n";
                person_file2 >> friends ; cout << "   - " << friends;  
                //cout << " "; person_file2 >>age; cout << "(" << age << ")" << " born in ";person_file2 >> place_of_birth; cout << place_of_birth << endl;
                person_file2.close();
            }
            //this while loop runs until the end of file has been reached
    }            
                
   person_file2.close();          
}   

  


