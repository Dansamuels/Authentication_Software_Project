#include "person.h"
#include <iostream>
#include <fstream>


using namespace std;

// This function encourages the user to pick option one or two
// and calls different methods implemented in person.cpp file
main()
{
    int opt;   // this integer stores the number the user enters
    cout << endl <<"Please select a number for the option of:\n\n1-Login\n2-Register\n\nOption: ";
    cin >> opt;
     if(opt == 1)
        {
            Person p1;
            p1.get_name_password();
        }
         else if(opt == 2)
        {
            Person p;
            p.getInfo();
            p.enteredInfo();
        }
    return 0;
}

