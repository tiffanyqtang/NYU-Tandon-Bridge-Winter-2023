#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);

bool isSorted(int arr[], int arrSize);

int main(){
    int size = 4;
    int arr[size] = {2, -1, 3, 10};

    cout << sumOfSquares(arr, size) << endl;

    if (isSorted(arr, size)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    if(arrSize <= 0){
        return 0;
    }
    else{
        return (sumOfSquares(arr, arrSize - 1) + (arr[arrSize -1]* arr[arrSize -1]));
    }
}

bool isSorted(int arr[], int arrSize){
    if(arrSize == 0 || arrSize == 1){
        return true;
    }
    
    return arr[arrSize - 1] >= arr[arrSize - 2] && isSorted(arr, arrSize - 1); 
    // checks if the one in front is larger and it will recursively call program again
}