/*Write a program that computes how much a customer has to pay after purchasing two items*/

#include <iostream>
#include <string>
using namespace std;

const string Y = "Y";
const string N = "N";
const string y = "Y";
const string n = "N";

    int main(){
        double baseItem1, baseItem2, item1, item2;
        double taxRate, basePrice, priceFinal, priceTotal;
        double memberDiscount;
        string member;

        cout<<"Please enter the price of the first item"<<endl;
        cin>>baseItem1;
        cout<<"Please enter the price of the second item"<<endl;
        cin>>baseItem2;

        basePrice = baseItem1 + baseItem2; 

        if(baseItem1 < baseItem2){
            item1 = baseItem1 * 0.5;
            item2 = baseItem2;
        }
        else{
            item2 = baseItem2 * 0.5;
            item1 = baseItem1;
        }

        cout<<"Does the customer have a club card? (Y/N)"<<endl;
        cin>>member;

        if(member== "Y"){
            memberDiscount = 0.1;
        }
        else{
            memberDiscount = 0;
        }
        
        priceTotal = (item1 + item2) * (1 - memberDiscount);

        cout<<"Please enter the tax rate"<<endl;
        cin>>taxRate;
        taxRate = taxRate/100;

        priceFinal = priceTotal * (1 + taxRate);
       
       cout<<"The base price is "<<basePrice<<endl;
       cout<<"The price after discounts is "<<priceTotal<<endl;
       cout<<"The total price is "<<priceFinal<<endl;
       
        return 0; 
    }