/*Write a program that asks the user to enter an amount of money in the format of dollars
and remaining cents. The program should calculate and print the minimum number
of coins that are equivalent to the given amount*/

#include <iostream>
using namespace std;

const int DOLLAR= 100;
const int QUARTER= 25;
const int DIME= 10;
const int NICKEL= 5;
const int PENNY = 1;
    int main (){
            int amount_dollars, amount_cents, remaining_amount;
            int amount_quarters, amount_dimes, amount_nickels, amount_pennies;
            
            cout<<"Please enter your amount in the format of dollars and cents separated by a space:";
            cin>>amount_dollars>>amount_cents;
            cout<<amount_dollars<<" dollars and "<<amount_cents<<" cents are:\n";

            remaining_amount = amount_dollars*DOLLAR + amount_cents;
            amount_quarters = remaining_amount/QUARTER;
            remaining_amount = remaining_amount%QUARTER;
            amount_dimes = remaining_amount/DIME;
            remaining_amount = remaining_amount%DIME;
            amount_nickels = remaining_amount/NICKEL;
            remaining_amount = remaining_amount%NICKEL;
            amount_pennies = remaining_amount/PENNY;
            
            cout<<amount_quarters<<" quarters, "<<amount_dimes<<" dimes, "<<amount_nickels<<" nickels and "<<amount_pennies<<" pennies";


        return 0;
    }