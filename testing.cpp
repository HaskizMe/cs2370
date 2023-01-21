#include <iostream>
#include <string>
using namespace std;

int main() {

    string firstName;
    string middleName;
    string lastName;

    cin >> firstName >> middleName >> lastName;
    if(middleName.empty() || firstName.empty() || lastName.empty()){
        cout << lastName << ", " << firstName[0] << "." << endl;

    }
    else{
        cout << lastName << ", " << firstName[0] << "." << middleName[0] << "." << endl;

    }

   return 0;
}