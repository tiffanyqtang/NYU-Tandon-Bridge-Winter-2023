#include <iostream>
#include <string>
using namespace std;

const int TOTAL_LETTERS = 26;

void letterOccurence(string line, int occurence[]);

bool isAnagram(int occurence1[], int occurence2[]);

int main(){
    string line1, line2;
    int occurence1[TOTAL_LETTERS] = {};
    int occurence2[TOTAL_LETTERS] = {};

    cout << "Please enter two strings in two lines: "<< endl;
    getline(cin, line1);
    getline(cin, line2);

    letterOccurence(line1, occurence1);
    letterOccurence(line2, occurence2);

    if(isAnagram(occurence1, occurence2)){
        cout << "The two strings are anagrams" << endl;
    }
    else{
        cout << "The two strings are not anagrams" << endl;
    }

    return 0;
}
void letterOccurence(string line, int occurence[]){
    for(char letter : line){
        if(letter >= 'a' && letter <= 'z'){
            occurence[letter - 'a']++;
        }
        else if(letter >= 'A' && letter <= 'Z'){
            occurence[letter - 'A']++;
        }
    }
}
bool isAnagram(int occurence1[], int occurence2[]){
    for(int i = 0; i < TOTAL_LETTERS; i++){
        if((occurence1[i]) != (occurence2[i])){
            return false;
        }
    } 
        return true;
    
}