#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main() {
    int numTriangles;
    char symbol;

    cout << "Please enter the number of triangles: " << endl;
    cin >> numTriangles;
    cout << "Please enter a symbol: " << endl;
    cin >> symbol;

    printPineTree(numTriangles, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= m; space++) {
            cout << ' ';
        }

        for (int spaceAdd = 1; spaceAdd <= (n - i); spaceAdd++) {
            cout << ' ';
        }

        for (int star = 1; star <= (2 * i - 1); star++) {
            cout << symbol;
        }

        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, n - i, symbol);
    }
}