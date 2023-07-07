/*Implement a number guessing game. The program should randomly choose an integer between
1 and 100(inclusive), and have the user to try and guess the number
1. Use at most 5 guesses
2. Before each guess, the program announces:
    updated guessing range
    the number of guesses left
3. If the user guessed correctly the program should announce it and the amount of 
guesses used
4. if the user guess wrong and theres guesses left, program should tell user if they 
chose bigger or smaller. 
5. if the user can't guess in 5 tries then the program should reveal the number it chose
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int answer, guess, count, rangeLow, rangeHigh;

    srand(time(0));

    answer = (rand() %100) +1; 
    count = 0;
    rangeLow = 1;
    rangeHigh = 100; 

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;
    cout<<"Range:["<<rangeLow<<", "<<rangeHigh<<"], Number of guesses left: "<<5 - count<<endl;
    
    for(count = 1; count <= 5; count++){
        cout<<"Your guess:"<<endl;
        cin>>guess;

        if((count == 5)&&(guess != answer)){
            cout<<"Range:["<<rangeLow<<", "<<rangeHigh<<"], Number of guesses left: "<<5 - count<<endl;
            cout<<"Out of guesses! My number is "<<answer<<endl;
        }
        else if(guess == answer){
            cout<<"Range:["<<rangeLow<<", "<<rangeHigh<<"], Number of guesses left: "<<5 - count<<endl;
            cout<<"Congrats! You guessed my number in "<<count<<"guesses."<<endl;
        }
        else if(guess > answer){
            rangeHigh = guess - 1; 
            cout<<"Range:["<<rangeLow<<", "<<rangeHigh<<"], Number of guesses left: "<<5 - count<<endl;
            cout<<"Wrong! My number is smaller."<<endl;
        }
        else if(guess < answer){
            rangeLow = guess + 1;
            cout<<"Range:["<<rangeLow<<", "<<rangeHigh<<"], Number of guesses left: "<<5 - count<<endl;
            cout<<"Wrong! My number is bigger."<<endl;
        }
    }
        
    return 0;
}