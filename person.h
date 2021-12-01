#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>

using namespace std;
class Person
{
private:
    string name;
    int age;
    string place_of_birth;
    string password;
    int no_of_friends;
    string friends;
public:
    void getInfo();
    void enteredInfo(); 
    void get_name_password();
    unsigned int RSHash(const char* str, unsigned int length) ;    
};
#endif