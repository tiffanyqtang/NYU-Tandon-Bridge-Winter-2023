#include <iostream>
#include <string>
using namespace std;

string newString(string working);

bool isNum(string working);

int main(){
    string text, working;
    int length;

    cout << "Please enter a line of text: "<< endl;
    getline(cin, text);

    length = text.length();

    int start = 0;

    for(int end = 0 ; end <= length; end++){
        if((text[end] == ' ')|| (end == length) ){
            working = text.substr(start, end - start);
            cout << newString(working) << " ";
            start = end + 1;//start at next index
        }
    }
    cout<<"length: "<<length;

    return 0;
}

string newString(string working){
    int length = working.length();

    if(isNum(working) == true){
        for(int i = 0; i < length; i++){
            working[i] = 'x';
        }
    }
    else{
        working = working;
    }
    
    return working;
}

bool isNum(string working){
    int length = working.length();

    for(int i = 0; i < length; i++){
        if((working[i] < '0') || (working[i] > '9')) {
            return false;
        }
    }
    return true;
}