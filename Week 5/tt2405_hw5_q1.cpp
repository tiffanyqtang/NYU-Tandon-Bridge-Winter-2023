/*Write a program that reads a positive integer n from the user and prints out a nxn multiplication table
colomns should be spaced by a tab*/

#include <iostream>
using namespace std;

    int main(){
        int n, row, column, product;
        cout<<"Please enter a positive integer:"<<endl;
        cin>>n;

        for(row= 1; row<=n; row++){//row number
           for(column = 1; column<=n; column++){//move through columns in a row
                product = row * column;
                cout<<product<<"\t";
           }
           cout<<endl;//move to next row
        }
       

        return 0;
    }