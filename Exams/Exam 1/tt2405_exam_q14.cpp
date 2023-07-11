#include <iostream>
using namespace std; 
    int main(){
        bool flag; 
        int numWorking, input, digitSum, digit;
        int group1, group2, group3, group4;

        flag = true;
        group1 = 0;
        group2 = 0;
        group3 = 0;
        group4 = 0;
        cout << "Please enter a sequence of numbers (with at least 1-digitand at most 8 digits), each one in a separate line. \n";
            cout << "End your sequence by typing -1.\n";
        while(flag == true){//this loop will continue to take the input until -1 is hit
            
            cin >> input;
           
            digitSum = 0;
           
            if(input != -1){ // if the input is not -1, this loop will sort number via sum of digits
                numWorking = input;
               
                while(numWorking != 0){// this loop moves through the digits and sums them up
                    digit = numWorking % 10; 
                    numWorking = numWorking / 10;
                    digitSum = digitSum + digit; 
                }
                if(digitSum < 10){
                    group1++;
                }
                else if((digitSum >= 10) && (digitSum < 20)){
                    group2++;
                }
                else if((digitSum >= 20) && (digitSum < 30)){
                    group3++;
                }
                else if((digitSum >= 30)){
                    group4++;
                }
            }
            else{ //end sequence
                flag = false;
            }
        }
        cout << "Total count of numbers in the Numbers Group 1; " << group1 << endl;
        cout << "Total count of numbers in the Numbers Group 2; " << group2 << endl;
        cout << "Total count of numbers in the Numbers Group 3; " << group3 << endl;
        cout << "Total count of numbers in the Numbers Group 4; " << group4 << endl;
        return 0;
    }