#include <iostream>
#include <vector>
using namespace std;


vector<int> merge(vector<int>start, int left, int mid, int right){
int i = left; //starting index for left
int j = mid + 1; // starting index for right

vector<int> temp; //temp vector for rearranging
temp.clear();

while(i < mid && j <= right){
    if(start[i] <= start[j]){
        temp.push_back(start[i]);
        i++;
    }
    else{
        temp.push_back(start[j]);
        j++;
    }
}
while(i <= mid){ 
    temp.push_back(start[i]);
    i++;
}
while(j <= right){
    temp.push_back(start[j]);
    j++;
}

return temp;

}

vector<int> divideConquer(vector<int>start, int left, int right){
    vector<int> minMax;
    vector<int> sortedV;

    if(left == right){
        minMax.push_back(start[0]); //if there is one item, it will be the only item in the returned vector
    }
    else{
    int mid = (left + right)/2;
    divideConquer(start, left, mid); // recursively calling to split
    divideConquer(start, mid + 1, right);
    sortedV = merge(start, left, mid, right);// this will merge the shards, find min and max from this
    for(int i = 0; i<= right; i++){
        cout<<sortedV[i]<<" ";
    }
    cout<<endl;
    minMax.push_back(sortedV[0]);
    minMax.push_back(sortedV[right]);
    }
   
    return minMax;
}

int main(){
vector <int> startNum{7};
int left = 0;
int right = startNum.size()-1;
vector<int> minMax;
minMax = divideConquer(startNum, left, right);

for(int i = 0; i <minMax.size(); i++ ){
    cout<<minMax[i]<<" ";
}

return 0;
}