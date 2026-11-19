#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std ;
float midValue(float x , float y){
    return ((x+y)/2.0f);
}
float func(float x){
    return (cos(x)-x*exp(x));
}

int main (){
    float x ,y ;
    cout<<"Enter the value of X0: ";
    cin>>x;
    cout<<"Enter the value of X1: ";
    cin>>y;
    int iteration = 1 ;
    float tolerance = 0.00001;
    cout << left << fixed << setprecision(5);
    cout << "\n" << setw(12) << "Iteration"
         <<setw(15)<<"a"
         <<setw(15)<<"b"
         <<setw(15)<<"f(a)"
         <<setw(15)<<"f(b)"
         <<setw(15)<<"x=(a+b)/2"
         <<setw(15)<<"f(x)"
         <<setw(15)<<"New Interval"
         << endl;
         cout<<"----------------------------------------------------------------";
         cout<<"---------------------------------------------------"<<endl;
    while(iteration<100){
        float  middle ;
    if (func(x) * func(y) < 0){
        float fxA = func(x);
        float fxB = func(y);
        middle = midValue(x,y);
        float middleValueFunction = func(middle);

        if(fabs(middleValueFunction)<tolerance){
            break;
        }
        if(fxA*middleValueFunction<0){
            y=middle ;
        }
        else{
        x=middle ;
        }
         cout << left << fixed << setprecision(5);
    cout << "\n" << setw(12) << iteration
         <<setw(15)<<x
         <<setw(15)<<y
         <<setw(15)<<func(x)
         <<setw(15)<<func(y)
         <<setw(15)<<middle
         <<setw(15)<<middleValueFunction
         <<setw(1)<<x<<","<<y
         << endl;
        iteration++;
    }

    }
}
