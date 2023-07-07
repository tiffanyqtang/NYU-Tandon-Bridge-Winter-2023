/*Suppose John and Bill worked for some time and we want to calculate the total time
both of them worked. Write a program that reads number of days, hours, minutes
each of them worked, and print the total time they worked together as
days, hours, minutes*/

#include <iostream>
using namespace std;

const int DAY = 24*60;
const int HOUR = 60;
const int MINUTE = 1; 

    int main() {
        int days_John, hours_John, minutes_John;
        int days_Bill, hours_Bill, minutes_Bill;
        int total_time, num_days, num_hours, num_minute;

        cout<<"Please enter the number of days John has worked: ";
        cin>>days_John;
        cout<<"Please enter the number of hours John has worked: ";
        cin>>hours_John;
        cout<<"Please enter the number of minutes John has worked: ";
        cin>>minutes_John;

        cout<<"Please enter the number of days Bill has worked: ";
        cin>>days_Bill;
        cout<<"Please enter the number of hours Bill has worked: ";
        cin>>hours_Bill;
        cout<<"Please enter the number of minutes Bill has worked: ";
        cin>>minutes_Bill;

        total_time = days_John*DAY + days_Bill*DAY + hours_John*HOUR + hours_Bill*HOUR + minutes_John*MINUTE + minutes_Bill*MINUTE;
        num_days = total_time/DAY;
        total_time = total_time%DAY;
        num_hours = total_time/HOUR;
        total_time = total_time%HOUR;
        num_minute = total_time/MINUTE;

        cout<<"The total time both of them worked together is "<<num_days<<" days, "<<num_hours<<" hours and "<<num_minute<<" minutes.";

        return 0;
}

