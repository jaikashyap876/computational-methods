#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float func(float x){
    return ((x*x*x)-((x*x)+2));
}
float fn2(float x,float y , float fx ,float fy ){
    return (x-(fx*((x-y)/(fx-fy))));
}

int main(){
    float x , y;
    float previos = 0.00f ;
    cout<<("Enter the value of X(n-1) :");
    cin>>x;
    cout<<("Enter the value of X(n) :");
    cin>>y;
    int iteration = 1 ;
    float tolerance = 0.00001f;
    cout << left << fixed << setprecision(5);
    cout << "\n" << setw(12) << "Iteration"
         <<setw(15)<<"X(n-1)"
         <<setw(15)<<"Fx(n-1)"
         <<setw(15)<<"X(n)"
         <<setw(15)<<"Fx(n)"
         <<setw(15)<<"X(n+1)"
         <<setw(15)<<"Fx(n+1)"
         << endl;
         cout<<"------------------------------------------------";
         cout<<"------------------------------------------------"<<endl;
    if(func(x)*func(y)<0){
        while(iteration<100){
        float fx = func(x);
        float fy = func(y);
        float fnext = fn2(x,y,fx,fy);
        if(abs(fnext - y) < tolerance){
            cout<<"Root is "<<y;
            break;
        }
        else{
            x=y;
            y=fnext;
        }
          cout << left << fixed << setprecision(5);
    cout << "\n" << setw(12) << iteration
         <<setw(15)<<x
         <<setw(15)<<fx
         <<setw(15)<<y
         <<setw(15)<<fy
         <<setw(15)<<fnext
         <<setw(15)<<func(fnext)
         << endl;
        iteration++;
    }

    }
    else{
        cout<<"Enter another input" ;
    }

}
