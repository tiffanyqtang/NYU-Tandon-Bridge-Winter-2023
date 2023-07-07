#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main(){
    string str;

    cout << "Please enter a word: "; 
    cin >> str;

    if(isPalindrome(str)){
        cout << str << " is a palindrome \n"; 
    }
    else{
        cout << str << " is not a palindrome \n";
    }

    return 0;
}

bool isPalindrome(string str){
    string reverse, temp;
    int index; 

    for(index = str.length() - 1; index >= 0; index-- ){//moves through indices backwards
        reverse += str[index];
        }

        return(str == reverse);
    }
