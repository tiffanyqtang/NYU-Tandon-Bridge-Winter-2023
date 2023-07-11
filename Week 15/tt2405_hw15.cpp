#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
/*input file into linked list, then sort out into two vectors of pay and owe*/
//make functions for code is done

template <class T>
class LList;

template <class T>
class LListNode{
private:
    T data;
    LListNode<T>* next;
    LListNode<T>* prev;
public:
    LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) : data(newdata), next(newnext), prev(newprev) {}
    T getData() const {return data;}
    T& getDataReference(){ return data;}
    void setData(T newdata){data = newdata; }
    LListNode<T>* getNext() const {return next; }
    LListNode<T>* getPrev() const {return prev; }
    friend class LList<T>;
};

template <class T>
class LList{
private:
    LListNode<T>* head;
    LListNode<T>* tail;
public:
    LList();
    ~LList();
    LList(const LList<T>& rhs);
    LList<T>& operator=(const LList<T>&rhs);

    void clear(){while(!isEmpty()) pop_front();}
    void push_back(const T& data){tail->prev = new LListNode(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
    void push_front(const T& data){head->next = new LListNode(data, head->next, head); head->next->next->prev = head->next; }
    T pop_back();
    T pop_front();
    int size();
    bool isEmpty(){return head->next == tail; }
    LListNode<T>* getHeadPointer() const {return head; }
    LListNode<T>* getTailPointer() const {return tail; }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>&rhs){
    if(this == &rhs){
        return *this;
    }
    clear();
    LListNode<T>* ptr = rhs.head->next;
    while(ptr !=rhs.tail){
        push_back(ptr->data);
    }
    return *this;
}
template <class T>
int LList<T>::size(){
    LListNode<T>* ptr = head->next;
    int count = 0;
    while (ptr != tail){
        count++;
        ptr = ptr->next;
    }
    return count;
}
template <class T>
T LList<T>::pop_back(){
    if(tail->prev == head){
        return T();
    }
    T retval = tail->prev->data;
    LListNode<T>* nodeToDelete = tail->prev;
    tail->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    delete nodeToDelete;
    return retval;
}

template <class T>
T LList<T>::pop_front(){
    if(tail->prev == head){
        return T();
    }
    T retval = head->next->data;
    LListNode<T>* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    head->next->prev = head;
    delete nodeToDelete;
    return retval;
}
template <class T>
LList<T>::~LList(){
    clear();
    delete head;
    delete tail;
}
template <class T>
LList<T>::LList(const LList<T>& rhs){
    head = new LListNode<T>();
    tail = new LListNode<T>();
    head->next = tail;
    tail->prev = head;
    *this = rhs;
}
template <class T>
LList<T>::LList(){ // build two dummy nodes
    head = new LListNode<T>();
    tail = new LListNode<T>();
    head->next = tail;
    tail->prev = head;
}

class BillInfo{
public:
    BillInfo();
    BillInfo(double newDifference);
    BillInfo(double newPaid, double newDifference, string newName);
    double get_amountPaid()const {
        return amountPaid;
    }
    void set_amountPaid(double newPaid){
        amountPaid = newPaid;
    }
    double get_difference()const{
        return difference;
    }
    void set_difference(double newDifference){
        difference = newDifference;
    }
    string get_name()const{
        return name;
    }
    void set_name(string newName){
        name = newName;
    }
private:
    double amountPaid;
    double difference;
    string name;
};

BillInfo::BillInfo(){
    amountPaid = 0.0;
    difference = 0.0;
    name = "none";
}
BillInfo::BillInfo(double newDifference){
    difference = newDifference;
}
BillInfo::BillInfo(double newPaid, double newDifference, string newName){
    amountPaid = newPaid;
    difference = newDifference;
    name = newName;
}

void openInputFile(ifstream& inFile){
    string fileName;
    cout<<"What is the file name?";
    cin>>fileName;
    inFile.open(fileName);
    while(!inFile){
        cout<<"FILE FAILED TO OPEN!"<<endl;
        cout<<"What is the file name?";
        cin>>fileName;
        inFile.clear();//clear the file flags
        inFile.open(fileName);
    }
}
void store_list(LList<BillInfo>& list, ifstream& file){
    double tempAmount = 0.0;
    double tempDifference = 0.0;
    string tempName; 
    while (file >> tempAmount){ //storing into LL
        file.ignore(9990, ' ');
        getline(file, tempName);
        BillInfo tempInfo(tempAmount, tempDifference, tempName);
        list.push_back(tempInfo);
    }
}
LListNode<BillInfo>* resetPtr(LList<BillInfo>& list, LListNode<BillInfo>*& ptr){
    ptr = list.getHeadPointer()->getNext();
    return ptr;
}
class Owed{
private:
    string name;
    string receiver;
    double owed;
public:
    Owed(string newName = "", string newReceiver = " ", double newOwed = 0): name(newName), receiver(newReceiver), owed(newOwed){}
    string get_name() const{return name; }
    string get_receiver() const{return receiver; }
    double get_owed() const{return owed; }
    void set_name(string newname){name = newname; }
    void set_receiver(string newreceiver){receiver = newreceiver; }
    void set_owed(double newowed){owed= newowed; }
};

double calculateEvenSplit(LListNode<BillInfo>*& ptr){
    double splitAmount; 
    double totalAmount = 0.0;
    int people = 0;
    while(ptr->getNext() !=nullptr){//find out even split
        double currentAmount = (*ptr).getData().get_amountPaid();
        totalAmount += currentAmount;
        ptr = ptr->getNext();
        people++;
    }
    splitAmount = totalAmount / people;
    return splitAmount;
}
void fillVectors(vector<LListNode<BillInfo>>& v1, vector<LListNode<BillInfo>>& v2, vector<LListNode<BillInfo>>& v3, LListNode<BillInfo>*& ptr, double splitAmount){
    while(ptr->getNext() !=nullptr){//find difference
        double tempDifference;
        double currentAmount = (*ptr).getData().get_amountPaid();
        tempDifference = splitAmount - currentAmount;
        ptr->getDataReference().set_difference(tempDifference);//gotta update via reference bc pointers
        if(tempDifference < 0){//neg
            v1.push_back(*ptr);
        }
        else if(tempDifference == 0){//zero
            v2.push_back(*ptr);
        }
        else if(tempDifference > 0){//pos
            v3.push_back(*ptr);
        }
        ptr = ptr->getNext();
    }
}
void fillOwedVector(vector<Owed>& owedAmount, vector<LListNode<BillInfo>>& pos, vector<LListNode<BillInfo>>& zero, vector<LListNode<BillInfo>>& neg){
    int negCount = 0;
    int posCount = 0;
    double updatedDifference = neg[negCount].getData().get_difference() + pos[posCount].getData().get_difference();
   
    while((negCount < neg.size())&&(posCount < pos.size())){
        double updatedDifference;
        string payReceive;
        string payer;
        double payAmount;

        updatedDifference = (neg[negCount].getData().get_difference()) + (pos[posCount].getData().get_difference());
    
            if(updatedDifference > 0){
                payer = pos[posCount].getData().get_name();
                payReceive = neg[negCount].getData().get_name();
                payAmount = abs(neg[negCount].getData().get_difference());
                negCount++;//can move onto the next in the negative list
                pos[posCount].getDataReference().set_difference(updatedDifference);//cannot move on to nex posPers, because there is still balance on this person
                Owed temp(payer, payReceive, payAmount);
                owedAmount.push_back(temp);
            }
            else if(updatedDifference < 0){
                payer = pos[posCount].getData().get_name();
                payReceive = neg[negCount].getData().get_name();
                payAmount = pos[posCount].getData().get_difference();
                posCount++; //posPerson paid off all their debts, can move on the pos vector
                neg[negCount].getDataReference().set_difference(updatedDifference);//set by reference!!!!
                Owed temp(payer, payReceive, payAmount);
                owedAmount.push_back(temp);
            }
            else if(updatedDifference == 0){
                payer = pos[posCount].getData().get_name();
                payReceive = neg[negCount].getData().get_name();
                payAmount = pos[posCount].getData().get_difference();
                Owed temp(payer, payReceive, payAmount);
                owedAmount.push_back(temp);
                posCount++;//can move onto the next in both lists, balances have been equaled
                negCount++;
            }
    }
}

int main(){
    ifstream inFile;
    openInputFile(inFile);
    LList<BillInfo> bill_list;
    store_list(bill_list, inFile);

    LListNode<BillInfo>* aPtr = nullptr;
    resetPtr(bill_list, aPtr);

    double evenSplit = calculateEvenSplit(aPtr);

    resetPtr(bill_list, aPtr);
    vector<LListNode<BillInfo>> neg, zero, pos; //vector of dereference pointer to access data in my list
    //function to fill vectors, must pass by reference! same with the pointer
    fillVectors(neg, zero, pos, aPtr, evenSplit);
    
    vector<Owed> owedAmounts;
    fillOwedVector(owedAmounts, pos, zero, neg);

    for(int i = 0; i < zero.size(); i++){
        cout<<zero[i].getData().get_name()<<" you don't need to do anything"<<endl;
    }
    for(int i = 0; i < owedAmounts.size();i++){
        cout<<owedAmounts[i].get_name()<<" give "<<owedAmounts[i].get_receiver()<<" $"<<owedAmounts[i].get_owed()<<" dollars"<<endl;
    }
    cout<<"In the end you should all have spent $ "<<evenSplit<<" dollars"<<endl;
    return 0;
}  