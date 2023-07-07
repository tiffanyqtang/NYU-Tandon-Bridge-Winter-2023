#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

void printArr(int arr[], int size);

int main(){
    const int n = 6;
    int arr[n] = {3, 1, 3, 0, 6, 4};
    int resArrSize = 0;

    int* missingArr = findMissing(arr, n, resArrSize);

    cout << "array size: " << resArrSize << endl; 
    cout << "Missing numbers: " << endl;

  

    printArr(missingArr, resArrSize);

    delete [] missingArr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int* numOccurArr = new int[n +1]();
    
    for(int i = 0; i < n; i++){
        numOccurArr[arr[i]]++;
    }

    int* missingArr = new int[n]; 
    int count = 0;

    for(int i = 0; i < (n + 1); i++){
        if(numOccurArr[i] == 0){
            missingArr[count++] = i;
        }
    }

    resArrSize = count;

    delete [] numOccurArr;

    return missingArr;

}
void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

