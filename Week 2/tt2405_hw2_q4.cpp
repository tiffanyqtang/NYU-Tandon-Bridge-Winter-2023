/*Write a program that reads from the user two positive integers, and prints the result of
when we add, subtract, multiply, divide, div and mod them*/

#include <iostream>
using namespace std;

    int main(){
        int num1, num2;
        int add, sub, mult, div, mod;
        double double_num1, double_num2, divide;

        cout<<"Please enter two positive integers, separated by a space: ";
        cin>>num1>>num2;

        double_num1 = (double)num1;
        double_num2 = (double)num2;

        add = num1+num2;
        sub = num1-num2;
        mult = num1*num2;
        divide = double_num1/double_num2;
        div = num1/num2;
        mod= num1%num2;

        cout<<num1<<" + "<<num2<<" = "<<add<<endl;
        cout<<num1<<" - "<<num2<<" = "<<sub<<endl;
        cout<<num1<<" * "<<num2<<" = "<<mult<<endl;
        cout<<num1<<" / "<<num2<<" = "<<divide<<endl;
        cout<<num1<<" div "<<num2<<" = "<<div<<endl;
        cout<<num1<<" mod "<<num2<<" = "<<mod<<endl;
        
        return 0;
    }