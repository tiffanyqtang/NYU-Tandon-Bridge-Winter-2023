/*Write a program that prompts for the weight in pounds and height in inches
and prints out the weight status for the person
BMI = (weight)/(height*height), in kg and meter
1 pound = 0.453592 kilos
1 inch = 0.0254 meters*/

const double KILO_CONVERSION = 0.453592;
const double METER_CONVERSION = 0.0254;

#include <iostream>
using namespace std;
    
    int main(){
        double pounds, inches, kilos, meters, bmi;

        cout<<"Please enter weight (in pounds):"<<endl;
        cin>>pounds;
        cout<<"Please enter height (in inches):"<<endl;
        cin>>inches;

        kilos = pounds * KILO_CONVERSION;
        meters = inches * METER_CONVERSION;
        bmi = kilos / (meters * meters);

        if (bmi < 18.5){
            cout<<"The weight status is: Underweight"<<endl;
        }
        else if((bmi >= 18.5) && (bmi < 25)){
            cout<<"The weight status is: Normal"<<endl;
        }
        else if((bmi >= 25) && (bmi < 30)){
            cout<<"The weight status is: Overweight"<<endl;
        }
        else if(bmi >= 30){
            cout<<"The weight status is: Obese"<<endl;
        }
        return 0;
    }