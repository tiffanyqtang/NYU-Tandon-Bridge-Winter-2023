#include <iostream>
#include <string>
using namespace std;


    int printMonthCalendar (int numOfDays, int startingDay); 
    //this function is given: number of days in the month
    //starting day is a number 1-7 that represents the day in the week for the first day
    //1 is monday
    //function needs to print a formatted monthly calendar of the month and return a number 1-7 for the last day of the month

    void printYearCalendar (int year, int startingDay);
    //function is given a year, and a starting day

    bool isLeapYear(int year);

    int daysFeb(int year);

    int main(){
        int year, startingDay, numOfDays;
        cout<<"Enter the year"<<endl;
        cin>>year;
        cout<<"Enter starting day"<<endl;
        cin>>startingDay;
        printYearCalendar(year, startingDay);
      
        return 0;
    }

    int printMonthCalendar (int numOfDays, int startingDay){
        int endingDay, day;

        cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

        for(int i = 1; i < startingDay; i++){ //tabs at start of month
            cout << "\t";
        }

        for(day = 1; day <= numOfDays; day++){
    
               
                if(day == numOfDays || (startingDay + day - 1) % 7 == 0){ //weeks, and end month
                   cout << day << endl;
                }
                else{
                    cout << day << "\t";
                }
        }
        endingDay = (startingDay + (day - 2)) % 7;// -2 because starting day includes first day, and day++ counts extra 1. 
    
        return endingDay;
        
    }

    bool isLeapYear(int year){
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
            return true;
        }
        else{
            return false;
        }
    }

    int daysFeb(int year){
        if(isLeapYear(year) == true){
            return 29;
        }
        else{
            return 28;
        }
    }

    void printYearCalendar (int year, int startingDay) {
        cout << "January " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1;
        cout << endl;

        cout << "February " << year << endl;
        startingDay = printMonthCalendar(daysFeb(year), startingDay) + 1;
        cout << endl;

        cout << "March " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1; 
        cout << endl;

        cout << "April " << year << endl;
        startingDay = printMonthCalendar(30, startingDay) + 1;
        cout << endl;

        cout << "May " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1;
        cout << endl;

        cout << "June " << year << endl;
        startingDay = printMonthCalendar(30, startingDay) + 1;
        cout << endl;

        cout << "July " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1;
        cout << endl;

        cout << "August " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1;
        cout << endl;

        cout << "September " << year << endl;
        startingDay = printMonthCalendar(30, startingDay) + 1;
        cout << endl;

        cout << "October " << year << endl;
        startingDay = printMonthCalendar(31, startingDay) + 1;
        cout << endl;

        cout << "November " << year << endl;
        startingDay = printMonthCalendar(30, startingDay) + 1;
        cout << endl;

        cout << "December " << year << endl;
        printMonthCalendar(31, startingDay);
        cout << endl;
    }