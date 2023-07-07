/*Write two versions of a program that reads a sequence of positive integers from the user, calculates their geometric mean and prints it
Version 1. first read the length of sequence, then execute
Version 2. Keep reading the numbers until a -1 is input*/

#include <iostream>
#include <cmath>
using namespace std;

    int main(){
        cout<<"Section a. "<<endl;
    
        double n, product, variable;
        double mean;
        double count;
        cout<<"Please enter the length of the sequence: "<<endl;
        cin>>n;
        product = 1;
        cout<<"Please enter your sequence:"<<endl;
        for(int i = 1; i <=n; i++){
            cin>>variable;
            product = product * variable;
        }   
        mean = pow(product, (1/n));
        cout<<"The geometric mean is: "<<mean<<endl;
         

        cout<<"Section B. "<<endl;

        cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. ";
        cout<<"End your sequence by typing -1:"<<endl;
        product = 1;
        count = 0;
        while(variable != -1){
            cin>>variable;
           if(variable != -1){
            count++;
            product = product * variable;
           }
           else {

           }
        }
        mean = pow(product, (1/count));
        cout<<"The geometric mean is: "<<mean<<endl;

        return 0;
    }