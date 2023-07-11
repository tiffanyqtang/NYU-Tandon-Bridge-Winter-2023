#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool hasNumber(string working);

int main(){
    string line, working;
    vector<string> inputs;
    int count = 0;

    cout<<"Please enter a non empty sequence of strings. Each string should \n";
    cout<<"be in a separate line and consists only lowercase letters and/or\n";
    cout<<"numbers. To indicate the end, input an empty string."<<endl;

    getline(cin, line);
    while(line.empty() == false){
        inputs.push_back(line);
        getline(cin, line);
    }
   
    for(int i= 0; i < inputs.size(); i++){//go through inputs vector
        working = inputs[i]; //working with the ith string in vector
        if(hasNumber(working) == true){
            cout<<working<<" "<<endl;
        }
        else{
            count++;
    }
        working.clear();
    }

    cout<<"Number of strings with only lowercase letters: "<<count;

    return 0;
}


bool hasNumber(string working){
    for(int i = 0; i < working.length(); i++){
        if(working[i] >= '0' && working[i] <= '9'){
            return true;
        }
    }
}