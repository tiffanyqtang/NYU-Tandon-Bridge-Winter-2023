/*write a program that asks the user to enter a number of quarters,
dimes, nickels and pennies and then outputs the monetary value of the coins
in the format of dollars and remaining cents
Program should interact such: 
Please enter number of coins: 
# quarters
# dimes
# nickels
# pennies
the total is 4 dollars and 37 cents*/

#include <iostream>
using namespace std;

const int DOLLAR = 100;
    int main (){
        int number_of_quarters, number_of_dimes, number_of_nickels, number_of_pennies;
        int value_quarters, value_dimes, value_nickels, value_pennies;
        int total_amount, amount_dollar, amount_cents;

        cout<<"Please input the amount of coins\n";
        cout<<"Number of quarters: \n";
        cin>>number_of_quarters;
        cout<<"Number of dimes: \n";
        cin>>number_of_dimes;
        cout<<"Number of nickles: \n";
        cin>>number_of_nickels;
        cout<<"Number of pennies: \n";
        cin>>number_of_pennies;

        value_quarters = number_of_quarters*25;
        value_dimes = number_of_dimes*10;
        value_nickels = number_of_nickels*5;
        value_pennies = number_of_pennies*1;

        total_amount = value_quarters + value_dimes + value_nickels + value_pennies;
        amount_dollar = total_amount/100;
        amount_cents = total_amount%100;

        cout<<"The total is "<<amount_dollar<<" dollars and "<<amount_cents<<" cents";





        return 0;
    }