#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main(){
    int size = 6;
    int arr[size] = {5, 2, 11, 7, 6, 4};

    cout << "Your original array is: ";
    printArray(arr, size);

    oddsKeepEvensFlip(arr, size);
    cout << "Your rearranged array is: ";
    printArray(arr, size);

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    int* oddsArr = new int[arrSize];
    int oddCount = 0;
    int* evensArr = new int[arrSize];
    int evenCount = 0;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] % 2 != 0){
            oddsArr[oddCount++] = arr[i];
        }
    }
    for(int j = arrSize - 1; j >= 0; j--){
        if(arr[j] % 2 == 0){
            evensArr[evenCount++] = arr[j];
        }
    }
    for(int i = 0; i < (arrSize - evenCount); i++){
        arr[i] = oddsArr[i];
    }
    
    int count = 0;
    for(int i = (arrSize - evenCount); i < arrSize; i++){
        arr[i] = evensArr[count++];
    }
    delete [] oddsArr;
    delete [] evensArr;
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}