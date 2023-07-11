#include <iostream>
#include <string>
using namespace std;

int countConsonants(string S, int length);
    
int main(){
    string S = "helloT";
    int length = S.length();

    cout<<countConsonants(S, length);

    return 0;
}

int countConsonants(string S, int length){
    if(length == 0){
        return 0;
    }
    else{
        if(S[length -1] >= 'b' && S[length -1] <= 'z' && S[length - 1] != 'e'&& S[length - 1] != 'i'&& S[length - 1] != 'o'&& S[length - 1] != 'u'){
            return countConsonants(S, length -1) +1;
        }
        else if(S[length -1] >= 'B' && S[length -1] <= 'Z' && S[length - 1] != 'E'&& S[length - 1] != 'I'&& S[length - 1] != 'O'&& S[length - 1] != 'U'){
            return countConsonants(S, length -1) +1;
        }
        else{
            return countConsonants(S, length -1);
        }
    }
}