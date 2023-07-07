/*Write a program that asks the user to input a positive integer n, and print all of the
numbers from 1 to n that have more even digits than odd */

#include <iostream>
using namespace std;

    int main(){
        int numInput, countNum, countDigit, remaining;
        int countEven, countOdd;
        
        cout<<"Please enter a positive integer:"<<endl;
        cin>>numInput;
        for(countNum= 1; countNum<= numInput; countNum++){//increments up the numbers
            remaining = countNum;
            countEven = 0;
            countOdd = 0;
           while(remaining > 0){//moves through each digit of a number
                countDigit = remaining % 10;
                remaining = remaining / 10;
                
                if(countDigit%2 == 0){//if the digit is even, even counter goes up
                    countEven++;
                }
                else{
                    countOdd++;
                }
            }
            if(countEven>countOdd){//if the amount of even digits is greater, the number outputs
                cout<<countNum<<endl;
            }
            else{
                continue;
            }
            
        }
        return 0;
    }
