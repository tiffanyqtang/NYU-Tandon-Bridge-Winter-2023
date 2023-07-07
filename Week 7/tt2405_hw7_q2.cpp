#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
//will take pos int >=2, updates 2 output parameters with nums prop divors and sum

bool isPerfect(int num);

int main(){
    int num; 

    cout << "Please enter a positive integer greater or equal to 2" << endl;
    cin >> num;

    cout << "Perfect numbers between 2 and " << num << endl;
    for(int i = 2; i <= num; i++){ // perfect numbers
        if(isPerfect(i)){
        cout << i << endl;
        }
    }

    cout << "Amicable numbers between 2 and " << num << endl;
    for(int i = 2; i <= num; i++){
        int outSum1, outSum2, outCount1, outCount2;

        analyzeDividors(i, outCount1, outSum1);
        analyzeDividors(outSum1, outCount2, outSum2);

        if((i == outSum2) && (i < outSum1)){
            cout << "(" << i << ", " << outSum1 << ")\n";
        }
    }

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    outCountDivs = 0;
    outSumDivs = 0;
    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){ // if theres no remainder, then it is divisible
           outCountDivs++;
           outSumDivs += i;
        }
        else{
            continue;
        }
        }
    for(int i = sqrt(num); i > 1; i--){//# greater than 1 so won't include num
        int compDivs;
        if(num % i == 0){
            compDivs = num / i;
            outCountDivs++;
            outSumDivs += compDivs;
        }
        else{
            continue;
        }
    }
}

bool isPerfect(int num){
    int outCountDivs, outSumDivs;

    analyzeDividors(num, outCountDivs, outSumDivs);

    return(num == outSumDivs);
}