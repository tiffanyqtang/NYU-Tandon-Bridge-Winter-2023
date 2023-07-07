#include <iostream>
#include <vector>
using namespace std;

void main2();

void main1();

int main(){

    cout << "version 1:" << endl;
    main1();

    cout << "version 2:" << endl;
    main2(); 

    return 0;
}

void main2(){
vector<int>arr; 
vector<int>presentArr;
int num;

cout << "Enter a list of positive numbers with a negative number at the end" << endl;

int next;
cin >> next;

while(next > 0){
    arr.push_back(next);
    cin>>next;
}

cout << "Please enter you want to search" << endl;
cin >> num;

for(unsigned int i = 0; i < arr.size(); i++){
    if(arr[i] == num){
        presentArr.push_back(i);
    }
}

if(presentArr.size() > 0){
    cout << num << " appears in lines: ";
    for(unsigned int i = 0; i < presentArr.size(); i++){
        cout << presentArr[i] + 1<< " ";
    }
    cout << endl;
}
else{
    cout << "The number does not appear in the sequence " << endl;
}
}

void main1(){
    const int startSize = 100;
    bool flag = true;
    int count = 0;
    int num, i = 0;
    int* arr = new int[startSize];
    

    cout << "Please enter a sequence of positive integers with a negative number at the end." << endl;

    while(flag == true){
       
        cin >> arr[i];
        if(arr[i] < 0){
            flag = false;
        }
        else{
            count++;
            i++;
        }
    }

    cout << "Please enter a number you want to search" << endl;
    cin >> num;
    int* presentArr = new int[count];
    int j = 0;
    for(int i = 0; i < count; i++){
        if(num == arr[i]){
            presentArr[j++] = i;
        }
    }
    if(j > 0){
        cout << "The number appears in lines: ";
            for(int i = 0; i < j; i++){
                cout << presentArr[i] + 1 << " ";
            }
            cout << endl
    }
    else{
        cout << "The number does not appear in the sequence" << endl;
    }
    delete [] presentArr;
}