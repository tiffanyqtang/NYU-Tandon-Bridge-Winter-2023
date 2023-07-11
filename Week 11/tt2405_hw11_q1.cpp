#include <iostream>
using namespace std;

void printTriangle(int n);

void printOpositeTriangles(int n);

void printRuler(int n);

int main(){
    int n;

    cout <<"Please enter a positive integer: " << endl;
    cin >> n;

    printTriangle(n);


    cout << endl;

    printOpositeTriangles(n);

    cout << endl;

    printRuler(n);


    return 0;
}

void printTriangle(int n){
    if(n == 1){
        cout << "*" << endl;
    }
    else{
        printTriangle(n - 1); 
        for(int i = 0; i < n; i++){
            cout << "*";
        }
        cout << endl;
    }
}

void printOpositeTriangles(int n){
    if(n == 0){
        cout << "*" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << "*";
        }
        cout << endl;
        printOpositeTriangles(n - 1);
        for(int i = 0; i < n; i++){
            cout << "*";
        }
        cout << endl;
    }

}
void printRuler(int n){
    if(n < 1){
        return;
    }
    else{
        printRuler(n - 1);
        for(int i = 0; i < n; i++){
            cout << "-";
        }
        cout << endl;
        
        printRuler(n -1);
       
    }
}