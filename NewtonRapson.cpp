#include <iostream>
#include <iomanip>
using namespace std ;

float fun_x(float x){
    return ((x*x*x*x)-x-10);
}
float derivatedFun_x(float x){
    return (4*(x*x*x) - 1);
}
float newtonRapsonFormula(float x , float fx , float fdx){
    return (x-(fx/fdx));
}
int main(){
    float x = 1;
    cout<<"Enter initial Guess : ";
    cin>>x;
    int iteration = 1;
    cout << left << fixed << setprecision(5);
    cout << "\n" << setw(12) << "Iteration"
         << setw(15) << "Xn"
         << setw(15) << "F(Xn)"
         << setw(15) << "f'(Xn)"
         << setw(15) << "X(n+1)" << endl;
         cout<<"----------------------------------------------------------------";
        while(iteration<100){
        float fx = fun_x(x);
        float fdx = derivatedFun_x(x);
        float result = newtonRapsonFormula(x ,fx ,fdx);
          cout << left << fixed << setprecision(5);
            cout << "\n" << setw(12) << iteration
         << setw(15) << x
         << setw(15) << fx
         << setw(15) << fdx
         << setw(15) << result << endl;
        if(result == x){
                cout<<"The Root  is :"<<x;
        break;
        }
        x=result ;
        iteration++;
    }
}

