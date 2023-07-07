/*Write two versions of a program that reads a positive integer N, and prints the first n even numbers
in the first, use a while loop
in the second, use a for loop*/

#include <iostream>
using namespace std;

    int main(){
        cout<<"Section a."<<endl;

        int n;
        int counter, product;
        cout<<"Please enter a positive integer:"<<endl;
        cin>>n;

        counter= 1;
        while(counter<=n){
            product = counter*2;
            counter++;
            cout<<product<<endl;
        }

        cout<<"Section b."<<endl;

        for(counter=1; counter<=n; counter++){
            product = counter*2;
            cout<<product<<endl;
        }


        return 0;
    }