/*Write a program that asks the user to input a positive integer n, and prints a textual image
of an hourglass made of 2n lines with astericks*/

#include <iostream>
using namespace std;

    int main (){
        int n, star, n2, space, full;

        cout<<"Please enter a positive integer"<<endl;
        cin>>n;
        n2 = n;
        full = 2 * n - 1;
        for(n; n>0; n--){ //amount of lines going down, 4, 3, 2, 1
            for(space = 0; space < ((full - (2 * n - 1))/2); space++ ){//space per line
                cout<<" ";
            }
            for(star = 1; star <= (2*(n - 1) + 1); star++){//stars per line
            cout<<'*';
            }
            cout<<endl; 
        }
        for(int i = 1; i <= n2; i++){//amount of lines going up 1, 2, 3, 4
           for(space = 0; space < ((full - (2 * i - 1))/2); space++ ){
                cout<<" ";
           }
            for(star = 1; star <= (2*(i - 1) + 1); star++){
            cout<<'*';
            }
            cout<<endl; 
        }

        return 0;
    }