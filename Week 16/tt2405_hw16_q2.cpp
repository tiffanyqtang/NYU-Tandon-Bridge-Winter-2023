#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue{
private:
    vector<T> data;
    int start, size;
public:
    Queue();
    T top(){return data[start]; }
    T pop(){
        T temp = data[start];
        start++;
        size--;
        return temp;
    }
    void push(T newdata){size++; data.push_back(newdata); }
    bool isEmpty(){return data.size() == 0;}
    void clear(){data.clear(); start = 0; size = 0;}
    int getSize(){return size;}
};
template <class T>
Queue<T>::Queue(){
    start = 0;
    size = 0;
}

int main(){
    Queue<int> practiceQ;

    for(int i = 0; i < 10; i++){
        practiceQ.push(i);
    }

    cout<<"Size: "<<practiceQ.getSize()<<endl;
    cout<<"First value: "<<practiceQ.top()<<endl;

    practiceQ.pop();
    cout<<"After removing first in queue, the first value is: "<<practiceQ.top()<<" and the new size is: "<<practiceQ.getSize()<<endl;

    practiceQ.clear();
    cout<<"After clearing the size is: "<<practiceQ.getSize();
    if(practiceQ.isEmpty()){
        cout<<" and the queue is empty"<<endl;
    }
    else{
        cout<<"and the queue is not empty"<<endl;
    }

    practiceQ.push(42);
    practiceQ.push(12);
    cout<<"Pushed two values. Front is now: "<<practiceQ.top();
    cout<<" and the size is: "<<practiceQ.getSize();

    return 0;
}
