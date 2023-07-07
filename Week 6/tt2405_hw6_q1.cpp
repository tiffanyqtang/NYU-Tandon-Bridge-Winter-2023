#include <iostream>
using namespace std;

int fib(int n);

int main(){
    int num; 

    cout << "Please enter a positive integer: " << endl;
    cin >> num; 
    cout << fib(num);
    return 0;
}

int fib(int n){
    if(n == 1 || n == 2){ //the first two numbers of the sequence are 1
        return 1; 
    }
    else{ //the next number is the sum of the two previous numbers
        int nFib1, nFib2, nFib;

        nFib1 = 1; 
        nFib2 = 1; 

        for(int i = 3; i <= n; i++){
            nFib = nFib1 + nFib2; 
            nFib2 = nFib1;
            nFib1 = nFib;
        }

        return nFib;
    }


}