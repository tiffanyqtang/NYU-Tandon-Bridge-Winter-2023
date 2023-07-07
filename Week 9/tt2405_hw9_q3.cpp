#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);

int* getPosNum1(int* arr, int arrSize, int& outPosArrSize);
//returns base address of the array(with pos num), updates output parameter 
//with array's logical size

int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr);
//returns base address of array and uses the pointer outPosArrSizePtr to update the array's size

void getPosNum3(int* arr, int arrSize, int*& posArr3, int& outPosArrSize);
//updates output parameter outPosArr with base address of array
//and output parameter outPosArrSize with array's logical size;

void getPosNum4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main(){
    int outPosArrSize1, outPosArrSize2, outPosArrSize3, outPosArrSize4; 
    int arrSize = 6;
    int arr[arrSize] = {3, -1, -3, 0, 6, 4};

    cout << "The original array is: " << endl;
    printArray(arr, arrSize);

    int* posArray1 = getPosNum1(arr, arrSize, outPosArrSize1);
    cout << "Array from getPosNum1 is: "<< endl;
    printArray(posArray1, outPosArrSize1);
    cout << "The size of the positive array is:" << outPosArrSize1 << endl;
    
    int* posArray2 = getPosNum2(arr, arrSize, &outPosArrSize2);
    cout << "Array from getPosNum2 is: "<< endl;
    printArray(posArray2, outPosArrSize2);
    cout << "The size of the positive array is: "<< outPosArrSize2 << endl;

    int* posArr3 = nullptr;
    getPosNum3(arr, arrSize, posArr3, outPosArrSize3);
    cout << "Array from getPosNum 3 is: " << endl;
    printArray(posArr3, outPosArrSize3);
    cout << "The size of the positive array is: " << outPosArrSize3 << endl;

    int* posArray4 = nullptr;
    getPosNum4(arr, arrSize, &posArray4, &outPosArrSize4);
    cout << "Array from getPosNum4 is: " << endl;
    printArray(posArray4, outPosArrSize4);
    cout << "The size of the positive array is: " << outPosArrSize4 << endl;

    delete [] posArray4;
    delete [] posArr3;
    delete [] posArray2;
    delete [] posArray1;
    return 0;
}

int* getPosNum1(int* arr, int arrSize, int& outPosArrSize1){
    int* posArray1 = new int[arrSize];
    outPosArrSize1 = 0;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
          posArray1[outPosArrSize1++] = arr[i];
        }
    }
    return posArray1;
}

void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* getPosNum2(int* arr, int arrSize, int* outPosArrSizePtr){
    int* posArray2 = new int[arrSize];
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            posArray2[count++] = arr[i];
        }
    }
    *outPosArrSizePtr = count;
    return posArray2;
}
void getPosNum3(int* arr, int arrSize, int*& posArr3, int& outPosArrSize3){
    int* posArray3 = new int[arrSize];
    outPosArrSize3 = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            posArray3[outPosArrSize3++] = arr[i];
        }
    }
    posArr3 = posArray3;
}
void getPosNum4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int* posArray = new int [arrSize];
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            posArray[count++] = arr[i];
        }
    }
    *outPosArrPtr = posArray;
    *outPosArrSizePtr = count;
}