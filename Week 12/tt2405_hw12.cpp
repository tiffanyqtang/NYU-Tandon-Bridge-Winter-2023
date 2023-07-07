#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money {
public:
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    
    Money(long dollars, int cents);
    Money(double total);
    Money();

    double get_value();
    friend istream& operator>>(istream& ins, Money& amount);
    friend ostream& operator<<(ostream& outs, const Money& amount);
    friend bool operator!=(const Money& amount1, const Money& amount2){
        return (amount1.all_cents != amount2.all_cents);
    } 
    

private:
    long all_cents;
};


class CheckInfo{
private: 
    int checkNum;
    Money checkAmount;
    bool isCashed;

public:
    CheckInfo(int checkNum1, Money checkAmount1, bool isCashed1); //constructor
    CheckInfo();

    //below are accessors;
    int get_checkNum();
    Money get_checkAmount();
    bool get_isCashed();

    //setters
    void set_checkNum(int setCheckNum) {
        checkNum = setCheckNum;
    }
    void set_checkAmount(Money setCheckAmount){
        checkAmount = setCheckAmount;
    }
    void set_isCashed(bool setIsCashed){
        isCashed = setIsCashed;
    }

    //overloaded input output operators
    friend istream& operator>>(istream& input, CheckInfo& check){
        int is_cash;
        input >> check.checkNum >> check.checkAmount >> is_cash;
        if(is_cash == 1){
            check.isCashed = true;
        }
        else{
            check.isCashed = false;
        }

        return input;
    }
    friend ostream& operator<<(ostream& output, const CheckInfo& check){
        output << check.checkNum << ", " << check.checkAmount << ", " << check.isCashed;
        return output;
    }
    friend bool operator!=(const CheckInfo& check1, const CheckInfo& check2){
        return((check1.checkNum != check2.checkNum) || (check1.checkAmount != check2.checkAmount)||(check1.isCashed != check2.isCashed));
    }
    
};
int digit_to_int(char c);

Money totalCashedChecks(vector<CheckInfo>& checks);
Money totalDeposits(vector<Money>& deposits);

int main(){
    vector<CheckInfo> cashedChecks, notCashedChecks;
    vector<Money> deposits;
    CheckInfo check, emptyCheck(0, 0.00, 0);
    Money deposit, emptyDeposit(0), oldBalance, newUserBalance, newBankBalance;
    
    cout<<"Please enter the check number, amount on check (exclude dollar sign)";
    cout<<" and whether or not the check has been cashed"<<endl;
    cout<<"1(yes) or 0(no)"<<endl;
    cout<<"End output by entering 0 for check, 0.00 for amount, 0 for being cashed"<<endl;

    cin>>check;
    while(check != emptyCheck){ //array of class CheckInfo populated
        if(check.get_isCashed() == true){
            cashedChecks.push_back(check);
        }
        else{
            notCashedChecks.push_back(check);
        }
        cin>>check;
    }

    cout<<"The sum of the cashed checks is: "<< totalCashedChecks(cashedChecks)<<endl;

    cout<<"The sum of the uncashed checks is: "<< totalCashedChecks(notCashedChecks)<<endl;

    cout<<"Please enter the deposits (end deposit input by typing 0.00): "<<endl;

    cin>>deposit;
    while(deposit != emptyDeposit){
        deposits.push_back(deposit);
        cin>>deposit;
    }

    cout<<"The sum of the deposits is: "<<totalDeposits(deposits)<<endl;

    cout<<"Please enter the prior balance amount: "<<endl;
    cin>>oldBalance;

    cout<<"Please enter the new balance amount according to the account holder: "<<endl;
    cin>>newUserBalance;

    newBankBalance = oldBalance + totalDeposits(deposits) - totalCashedChecks(cashedChecks);
    cout<<"The balance according to the bank with only cleared checks is: "<< newBankBalance <<endl;

    cout<<"The difference between the account holders balance of "<<newUserBalance;
    cout<<" and the bank balance of "<<newBankBalance<<" is : ";
    cout<<newBankBalance - newUserBalance<<endl; 

    cout<<"The cashed checks are: "<<endl;
    for(int i = 0; i < cashedChecks.size(); i++){
        cout<<"Check number: "<< cashedChecks[i].get_checkNum();
        cout<<" with amount: "<< cashedChecks[i].get_checkAmount()<<endl;
    }

    cout<<"The un-cashed checks are: "<<endl;
    for(int i = 0; i < notCashedChecks.size(); i++){
        cout<<"Check number: "<< notCashedChecks[i].get_checkNum();
        cout<<" with amount: "<< notCashedChecks[i].get_checkAmount()<<endl;
    }
    return 0;
}

Money operator+(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator-(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money::Money(long dollars, int cents){
    if(dollars*cents < 0){
        cout<<"Illegal values"<<endl;
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(double total){
    all_cents = total*100;
}

Money::Money(){
    all_cents = 0;
}

double Money::get_value(){
    return (all_cents*.01);
}

istream& operator>>(istream& ins, Money& amount){
    char decimal_point, digit1, digit2;
    long dollars;
    int cents;

    

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;


    return ins;
}


ostream& operator<<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "-$" << dollars << '.';
    } else {
        outs << '$' << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

CheckInfo::CheckInfo(int checkNum1, Money checkAmount1, bool isCashed1){
    checkNum = checkNum1;
    checkAmount = checkAmount1;
    isCashed = isCashed1;
}

CheckInfo::CheckInfo(){
    checkNum = 0;
    checkAmount = 0;
    isCashed = 0;
}

int CheckInfo::get_checkNum(){
    return checkNum;
}

Money CheckInfo::get_checkAmount(){
    return checkAmount;
}

bool CheckInfo::get_isCashed(){
    return isCashed;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money totalCashedChecks(vector<CheckInfo>& checks){
    Money temp = 0;
    for(int i = 0; i < checks.size(); i++){
        temp= checks[i].get_checkAmount() + temp;
    }
    return temp;
}
Money totalDeposits(vector<Money>& deposits){
    Money temp = 0;
    for(int i = 0; i < deposits.size(); i++){
        temp = deposits[i] + temp;
    }
    return temp;
}