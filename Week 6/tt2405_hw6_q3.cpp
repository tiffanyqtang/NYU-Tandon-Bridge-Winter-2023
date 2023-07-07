#include <iostream>
using namespace std;

double eApprox(int n);

int main(){
    cout.precision(30);

    for(int n = 1; n <= 15; n++){
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}

double eApprox(int n){
    double sum, initial, factInv, fact;
        initial = 1.0;
        fact = 1;
        sum = initial;

        for(int i = 1; i <= n; i++){
            fact *= i;
            factInv = 1.0 / fact;
            sum = sum +  factInv;
        }
        
       

    return sum; 
}