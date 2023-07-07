#include <iostream>
#include <string>
using namespace std;


bool isDelimeter(char letter);

int amountWords(string line);

void letterOccurence(string line, int occurArray[]);

int main(){
    string line; 
    
    int countLetters;
    int occurArray[26] = {}; 
   

    cout << "Please enter a line of text" << endl;
    getline(cin, line);

    cout << amountWords(line) << '\t' << "words" << endl;

    letterOccurence(line, occurArray);

    return 0;
}

bool isDelimeter(char letter){
    if(letter == ' ' || letter == ',' || letter == '.'|| letter =='\n'){
            return true;
        }
    else{
        return false;
    }
}

int amountWords(string line){
    string word;
    int count = 0;

for(char letter : line){
        if(isDelimeter(letter) == true){
                count++;
                word.clear();
        }
        else{
        word += letter;
    }
    }
if(((line[line.length() - 1] >= 'a')&&(line[line.length() - 1] <= 'z')) ||((line[line.length() - 1] >= 'A')&&(line[line.length() - 1] <= 'Z'))){
    count++;
}
    return count;
}

void letterOccurence(string line, int occurArray[]){
    for(char letter : line){
        if(letter <= 'z' && letter >= 'a'){
            occurArray[letter - 'a']++;
        }       
        else if(letter <= 'Z' && letter >= 'A'){
            occurArray[letter - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(occurArray[i] != 0){
            char alphabet = 'a' + i;
            cout << occurArray[i] << '\t' << alphabet << endl;
        }
    }
}

