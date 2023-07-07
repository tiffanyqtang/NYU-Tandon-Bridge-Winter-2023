/*Write a program that asks the user to input three real numbers that go into the quadratic equation. 
Then it will classify one of the following: infinite number of solutions, no solution, no real solution, 
one real solution, two real solutions. If the solutions are real, print the solutions*/

#include<iostream>
#include<cmath>
using namespace std;

    int main(){
        double a, b, c, x, x1, x2;

        cout<<"Please enter the value of a: "<<endl;
        cin>>a;
        cout<<"Please enter the value of b: "<<endl;
        cin>>b;
        cout<<"Please enter the value of c: "<<endl;
        cin>>c;

        if((a == 0) && (b == 0) && (c ==0 )){
            cout<<"Infinite number of solutions"<<endl;
        }
        else if(((b * b)- (4 * a * c)) < 0){
            cout<<"No real solutions"<<endl;
        }
        else if((a == 0) && (b == 0)){
            cout<<"No solution";
        }
        else if(a == 0){
            x = (0 - c)/ b;
            cout<<"This equation has one single real solution x = "<<x<<endl;
        }
        else if((a != 0) && (b != 0) && (c != 0)){
            x1 = (((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a));
            x2 = (((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a));

                if(x1 = x2){
                    cout<<"This equation has one single real solution x = "<<x1<<endl;
                }
                else{
                cout<<"This equation has two real solutions x= "<<x1<<" and "<<x2<<endl;
                }
        }

        return 0;
    }