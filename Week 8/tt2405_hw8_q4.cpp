#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PASS[5] = {3, 3, 4, 6, 8};
const int PIN_SIZE = 5;
const int MAP_SIZE = 10;

bool isPin(int guess, int num[]);
//will see if the guess array matches Pin array

void fillNum(int num[], int numSize); 
//fills num array with random values

void printArray(int arr[], int arrSize);
//prints array

int main(){
    int guess; 
    int num[10]; 
    int pin[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
   

    cout << "Please enter your PIN according to the following mapping : \n";
    
    cout << "PIN: ";
    printArray(pin, MAP_SIZE);

    fillNum(num, MAP_SIZE);

    cout << "NUM: " ;
    printArray(num, MAP_SIZE);


        cin >> guess;
    

    
    if(isPin(guess, num)){
        cout << "Your pin is correct \n";
    }
    else{
        cout << "Your pin is not correct \n";
    }
    return 0;
}

void fillNum(int num[], int numSize){
    srand(time(0)); 
    for(int i = 0; i < numSize; i++){
        num[i] = (rand() % 3) + 1;
    }
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPin(int guess, int num[]){
    int encrypt;

    encrypt = 0;
    for(int i = 0; i < 5; i++){
            encrypt = 10 * encrypt + num[PASS[i]];
    }
    
        if(encrypt != guess){
        return false;
        }
        else{
        return true;
        }
    }
