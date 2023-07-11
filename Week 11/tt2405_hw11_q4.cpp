#include <iostream>
using namespace std;

int sumSpaces(int arr[], int size);

int main(){
    int size = 6;
    int arr[size] = {0, 3, 80, 6, 57, 10};

    cout << sumSpaces(arr, size) << endl;

    return 0;
}

int sumSpaces(int arr[], int size){
    if(size <= 3){
        return arr[size - 1];
    }
    else{
        int sum1 = sumSpaces(arr, size -1);
        int sum2 = sumSpaces(arr, size -2);

        if(sum1 > sum2){
            return sum2 + arr[size - 1];
        }
        else{
            return sum1 + arr[size - 1];
        }
    }
}
