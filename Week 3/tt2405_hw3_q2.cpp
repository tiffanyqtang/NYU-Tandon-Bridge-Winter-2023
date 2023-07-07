/*Write a program that asks user for name, graduation year, current year. THen display current status 
(not in college, freshman, sophomore, junior, senior, graduate)*/


#include <iostream>
#include <string>
using namespace std; 

    int main(){
        string name; 
        int gradYear, currentYear, yearsLeft;

        cout<<"Please enter your name"<<endl;
        cin>>name;

        cout<<"Please enter your graduation year"<<endl;
        cin>>gradYear;

        cout<<"Please enter current year"<<endl;
        cin>>currentYear;

        yearsLeft = gradYear - currentYear;

        if(yearsLeft > 4){
            cout<<name<<", you are not in college"<<endl;
        }
        else if(yearsLeft == 4){
            cout<<name<<", you are a freshman"<<endl;
        }
        else if(yearsLeft == 3){
            cout<<name<<", you are a sophomore"<<endl;
        }
        else if(yearsLeft == 2){
            cout<<name<<", you are a junior"<<endl;
        }
        else if(yearsLeft == 1){
            cout<<name<<", you are a senior"<<endl;
        }
        else if(yearsLeft < 1){
            cout<<name<<", you are graduated"<<endl;
        }
        return 0;
    }