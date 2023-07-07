#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
//takes arr and reverses it

void removeOdd(int arr[], int& arrSize);
//outputs only the even numbers in the end. Order stays the same. updates arrsize

void splitParity(int arr[], int arrSize);
//changes order so all odd numbers appear first, and even numbers last

void printArray(int arr[], int arrSize);

int main(){
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for(i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int arrSize){
    int j = 0;
    int temp; //cannot use temp array, using temp integer
    for(int i = arrSize - 1; i > (arrSize / 2); i-- ){//move bkwd through array
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
    j++;
    }
    
}
void removeOdd(int arr[], int& arrSize){
    int evenCount = 0;
   
    for(int i = 0; i < arrSize; i++){
        if((arr[i] % 2) == 0){//if even, put into that position, else move to next number
            arr[evenCount] = arr[i];
            evenCount++;
        }
    }

    arrSize = evenCount; //update array size
}
void splitParity(int arr[], int arrSize){//bubble even numbers to the end
    for(int i = arrSize - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if((arr[j] % 2) == 0){
                int temp = arr[j + 1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}