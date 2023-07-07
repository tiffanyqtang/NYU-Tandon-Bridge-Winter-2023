/*Write a program that ask the user to ener a real number, the it asks the
user to enter the method by which they want to round that number (floor, ceiling,
round). Use switch  statement*/

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

#include <iostream>
using namespace std;

    int main(){
        double num;
        int numRound, method;

        cout<<"Please enter a real number"<<endl;
        cin>>num;
        cout<<"Please enter your rounding method"<<endl;
        cout<<"1. Floor round \n";
        cout<<"2. Ceiling round \n";
        cout<<"3. Round to the nearest whole number\n";
        cin>>method;

        int numIntegral = num;
        double numDecimal = num - numIntegral;



        switch(method){ 
            case 1:
                if((num >=0)|| (numDecimal ==0)){
                     numRound = numIntegral;   
                cout<<numRound<<endl;
                }
                else if((num < 0)&&(numDecimal !=0)){
                     numRound = numIntegral -1;
                cout<<numRound<<endl;
                }
                break;
            case 2:
                if((num >= 0)&&(numDecimal !=0)){
                        numRound = numIntegral + 1;
                cout<<numRound<<endl;
                }
                else if((num < 0) || (numDecimal == 0)){
                        numRound = numIntegral;
                cout<<numRound<<endl;
                }
                break;
            case 3:
                if(numIntegral >= 0){
                    if(numDecimal >= 0.5){
                    numRound = numIntegral + 1;
                    }
                    else if(numDecimal < 0.5){
                    numRound = numIntegral;
                     }
                cout<<numRound<<endl;
                }
                else if(numIntegral < 0){
                    if(numDecimal <= -0.5){
                        numRound = numIntegral - 1;
                    }
                    else if(numRound > -0.5){
                        numRound = numIntegral;
                    }
                cout<<numRound<<endl;
                }
                break;
            default:
                cout<<"This is not an option."<<endl;

        }
        return 0;
    }