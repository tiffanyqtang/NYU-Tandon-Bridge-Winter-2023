/*Write a program that computes the cost of a long-distance call. 
Cost of the call is as follows: 
Call between 8am and 6pm on Monday - Friday; 0.40$ per min
Call before 8am or after 6pm Monday - Friday; 0.25$ per min
Any call on Saturday or sunday is 0.15$ per min*/

#include <iostream>
using namespace std;
    
    int main(){

        char dayCall, temp;
        int hour, min;
        int lengthCall;
        double priceCall;

        cout<<"Please input the length of the call in minutes"<<endl;
        cin>>lengthCall;
        cout<<"Please input the time the call started (24hr notation)"<<endl;
        cin>>hour>>temp>>min;
        cout<<"Please enter the day the call started (Mo, Tu, We, Th, Fr, Sa, Su)"<<endl;
        cin>>dayCall;
       
        if(dayCall=='Sa'){
            priceCall = lengthCall * 0.15;
        }
        else if(dayCall=='Su'){
            priceCall = lengthCall * 0.15;
        }
        else{
            if((hour >= 8) && (hour < 18)){
                priceCall = lengthCall * 0.40;
            }
            else{
                priceCall = lengthCall * 0.25;
            }
        }
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"The total cost of your call is: "<<priceCall<<" dollars"<<endl;

        return 0;
    }
