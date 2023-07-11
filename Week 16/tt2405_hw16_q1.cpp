#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;


void openInputFile(ifstream& inFile){
    string fileName; 
    cout<<"What is the file name?: ";
    cin>>fileName;
    inFile.open(fileName);
    while(!inFile){
        cout<<"File failed to open!"<<endl;
        cout<<"What is the file name?; ";
        cin>>fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}


bool isBalanced(ifstream& inFile){
    bool balanced, beginFlag = false;//use flag for begin and end
    stack<char> symbolsStack;
    char next;
    string word;//going to check if that word is begin or end,
    while(inFile){//ask in OH about eof
    inFile.get(next);
        /*if((next == '/')&&(inFile.get(next)=='/')){//check if comment
            inFile.ignore(9999, '/n');
        }
        else{
            inFile.seekg(-1); //if not comment, move the file pointer back one
        }*/

        if(((next >= 'a')&& (next <= 'z'))||(next >= 'A')&&( next <= 'Z')){//build words up, see if it is a word
            word += next;
        }
        else{
            word.clear();            
        }
        if(word == "begin"){ 
            //cout<<"begin happened"<<endl;  
            beginFlag = true;
        }
        if((word == "end") && (symbolsStack.empty())&& (beginFlag ==true)){
            //cout<<"end happened"<<endl;
            return true;
        }
        if((next == '(')||(next =='{')||(next == '[')){
            symbolsStack.push(next);
            //cout<<next<<", ";
        }

        if((next == ')') && (symbolsStack.top() == '(')){
            symbolsStack.pop();
            //cout<<"removed"<<next<<", ";
        }
        if((next == '}') && (symbolsStack.top() == '{')){
            symbolsStack.pop();
            //cout<<"removed"<<next<<", ";
        }
        if((next == ']') && (symbolsStack.top() == '[')){
            symbolsStack.pop();
            //cout<<"removed"<<next<<", ";
        }
    }
}
int main(){
    ifstream inFile;
    char next;
    string word;
    openInputFile(inFile);
    if(isBalanced(inFile) == true){
        cout<<"file is balanced."<<endl;
    }
    else{
        cout<<"file is not balanced."<<endl;
    }
    
    
    
    return 0;
}