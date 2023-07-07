#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main(){
    int num;
    cout<< "Please enter a positive integer >= 2:" << endl;
    cin >> num;

    printDivisors(num);

    return 0;
}

void printDivisors(int num){
    int compDivs;

    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){ // if theres no remainder, then it is divisible
            cout << i << " ";
        }
        else{
            continue;
        }
    }     
    for(int i = sqrt(num); i > 0; i--){
        if(num % i == 0){
            compDivs = num / i;
            cout << compDivs << " ";
        }
        else{
            continue;
        }
    }
}