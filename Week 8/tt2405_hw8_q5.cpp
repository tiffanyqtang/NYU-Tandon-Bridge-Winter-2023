#include <iostream>
#include <string>
using namespace std;



int main(){
    string name, lastName, firstName, middleName;
    
    cout << "Please enter your first, middle and last name \n";
    cin >> firstName >> middleName >> lastName;
    
    cout << lastName << ", " << firstName << " " << middleName[0] << ". \n"; 
    return 0;
}

