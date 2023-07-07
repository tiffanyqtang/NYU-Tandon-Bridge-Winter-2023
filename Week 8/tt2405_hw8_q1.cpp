#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

int main(){
    int size = 5, arr[size] = {1, 2, 3, 4, 5};

    reverseArray(arr, size);
    printArray(arr, size);

    return 0;
}

void reverseArray(int arr[], int arrSize){
int temp;
int last = arrSize -1;
for(int i = 0; i <= (arrSize/2); i++){
    temp = arr[i];
    arr[i] = arr[last -i];
    arr[last - i] = temp;
}

}
void printArray(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout<<arr[i]<<" ";
    }
}