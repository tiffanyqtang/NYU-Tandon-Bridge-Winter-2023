/*Will use a simplified version of the Roman Numerals System
A number in the simplified Roman numerals system is a sequence of Roman digits which follow these rules
1. the digits form a monotonically non-increasing sequence
    value of eqch digit is less than or equal to the value of the digit that came before it
2. there is no limit of times that M can appear in the number
    D L V can each appear at most one time
    C X I can each appear at most five times*/

const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5; 
const int I = 1; 

#include <iostream>
#include <string>
using namespace std;

    int main(){
        int num, numWorking, numInitial, count;
        string numRoman;
        cout<<"Enter decimal number:"<<endl;
        cin>>numInitial;
        numWorking = numInitial;
        num = numInitial;
        while((numWorking/M) != 0){ //will run until there is no more 1000ths place left
            numRoman = numRoman + "M";
            num = num - M;
            numWorking = num;
        }
        
        if((numWorking/D) != 0){
            numRoman = numRoman + "D";
            num = num - D;
            numWorking = num;
        }
        else{}

        for(count = 1; (count <= 4) &&((numWorking/C) != 0); count++){
                numRoman = numRoman + "C";
                num = num - C;
                numWorking = num;
            }

        if((numWorking/L) != 0){
            numRoman = numRoman + "L";
            num = num - L;
            numWorking = num;
        }
        else{}

        for(count = 1; (count <= 4) &&((numWorking/X) != 0); count++){
                numRoman = numRoman + "X";
                num = num - X;
                numWorking = num;
            }
        if((numWorking/V) != 0){
            numRoman = numRoman + "V";
            num = num - V;
            numWorking = num;
        }
        else{}
         for(count = 1; (count <= 4) &&((numWorking/I) != 0); count++){
                numRoman = numRoman + "I";
                num = num - I;
                numWorking = num;
            }
    

        cout<<numInitial<<" is "<<numRoman<<endl;
        return 0;
    }