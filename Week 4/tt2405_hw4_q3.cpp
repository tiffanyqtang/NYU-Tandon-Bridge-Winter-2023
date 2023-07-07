/*write a program that reads from the user a positive integer (in decimal representation)
and prints its binary base representation*/

 #include <iostream>
 #include <cmath>
 using namespace std;

    int main(){
        int numInitial, count, remainder;


        cout<<"Enter decimal number:"<<endl;
        cin>>numInitial;
        cout<<"The binary representation for "<<numInitial<<" is ";
        for((count = log2(numInitial)); count >= 0; count--){//how many positions, move down each position left to right
            remainder = pow(2, count);//amount remaining after 2^x
            
            if(numInitial >= remainder){//if amount is greater than position, need a 1 there
                cout<<'1';
                numInitial = numInitial - remainder;//subtract the position amount from the working amount to figure out new working amount
            }
            else{
                cout<<'0';
            }
        }
      
        return 0;
    }