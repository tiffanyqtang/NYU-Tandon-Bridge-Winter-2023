#include <iostream>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

bool isDelimeter(string sentence, char letter, int count);

void printArray(string wordArray[], int size);

int main(){
    string sentence;
    string* wordArray;
    int outWordsArrSize = 0;

    cout<<"Please enter a sentence: "<< endl;
    getline(cin, sentence);

    wordArray = createWordsArray(sentence, outWordsArrSize);
    cout<< "Amount of words in the sentence: " << outWordsArrSize << endl;
    printArray(wordArray, outWordsArrSize);
    
    delete [] wordArray;
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    string word;
    int count = 0;
    string* wordArray = new string [sentence.length()];

    for(char letter : sentence){
        count++;
        word+= letter;
        if(isDelimeter(sentence, letter, count) == true){
            outWordsArrSize++; // increase word count
            wordArray[outWordsArrSize - 1] = word;
            word.clear();
        }
    }
    

    return wordArray;
}

bool isDelimeter(string sentence, char letter, int count){// need counter to know you're in the last letter of the sentence
    
    if(letter == ' '){
        return true;
    }
    else if(count == sentence.length()){// end of sentence
        return true;
    }
    else{
        return false;
    }

}

void printArray(string wordArray[], int size){
    cout << "[";
    for(int i = 0; i < size; i++){
        cout << wordArray[i] << ", ";
    }
    cout << "]";
}