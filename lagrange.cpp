#include <iostream>
using namespace std ;
class input{
protected:
    int n ; 
    double fn ; 
    double x[20]; 
    double y[20];
public:
    void inputValue(){
        cout<<"Enter the length "<<endl;
        cin>>n ;
        cout<<"Enter the Value of X :";
        for(int i = 0 ; i < n ; i ++){
            cin>>x[i];
        }
        cout<<"Enter the Value of Y :";
        for(int i = 0 ; i < n ; i ++){
            cin>>y[i];
        }
        cout<<"Enter the F(n) "<<endl;
        cin>>fn ;
    }
    void displayValues(){
        cout<<"The Value of X :";
        for(int i = 0 ; i < n ; i ++){
            cout<<" "<<x[i];
        }
        cout<<"The Value of Y :";
        for(int i = 0 ; i < n ; i ++){
           cout<<" "<<y[i];
        }
    }
};
class lagrange : public input{
protected :
    double result = 0 ;
    double fy = 1;
public:
    void answer(){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++ ){
                if(i == j ){

                }
                else{
                    fy = fy *  (fn-x[j])/(x[i]-x[j]);
                }
            }
            result = result + fy*y[i] ;
            fy = 1 ;
        }
    }
    void displayAnswer(){
        cout<<"Interpolated value = "<<result<<endl; 
    }
};
int main(){
    lagrange method ;
    method.inputValue();
    method.answer();
    method.displayAnswer();
    
    return 0;
}