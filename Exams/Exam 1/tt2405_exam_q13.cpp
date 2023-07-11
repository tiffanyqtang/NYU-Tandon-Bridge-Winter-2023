#include <iostream>
using namespace std;
    int main(){
        int n, rows, rowsTotal, spaces, stars; 

        cout << "Please enter a positive integer" << endl;
        cin >> n;

        rowsTotal = 2 * n; 

        for(rows = 1; rows <= rowsTotal; rows++){ //move down rows
            for(spaces = 0; spaces <= (rowsTotal - rows); spaces++){ //spaces
                cout << " ";
            }
            for(stars = 1; stars <= rows; stars++){ //stars
                cout << "*";
            }
            cout << endl; //fin line
        }
        return 0;
    }