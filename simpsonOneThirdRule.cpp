#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
class simpsonOneThird
{
protected:
    float h, b, a;
    int n;
    float *x;
    float *fx;

public:
    simpsonOneThird()
    {
        cout << "Enter interval size : ";
        cin >> n;
        x = new float[n+1];
        fx = new float[n+1];
        cout << "Enter lower limit : ";
        cin >> a;
        cout << "Enter uppar limit : ";
        cin >> b;
    }
    void hValue()
    {
        h = (b - a) / n;
    }
    void inputArray()
    {
        for (int i = 0; i < n+1; i++)
        {
           x[i] = a + i * h;
        }
    }
};
class operation : public simpsonOneThird
{
public:
    float function(float x)
    {
        return (x*x*x);
    }
    float function2(float x)
    {
        // cout << "1.0 / (1 + x*x)\n";
        return 1.0 / (1 + x*x);
    }
    float function3(float x)
    {
        // cout << "Function = exp(-x * x)\n";
        return  exp(-x * x);
    }
    void findFx()
    {
        for (int i = 0; i <=  n; i++)
        {
            cout << "Function = x^3 \n";
            fx[i] = function(x[i]);
        }
    }
};
class formula : public operation
{
protected:
    double result = 0.00;

public:
    void findAnswer()
    {
        result = fx[0] + fx[n];
        for (int i = 1; i < n; i++)
        {;
            if (i == 0 || i == n)
            {
                result += fx[i];
            }
            else if (i%2== 0)
            {
                result += 2 * fx[i];
            }
            else
            {
                result += 4 * fx[i];
            }
        }
        result = result * (h/3);
    }
};
class display : public formula
{
public:
    void displayAnswer()
    {
        cout << "\n====================================\n";

        cout << "Enter array elements:\n";
        for (int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(6) << x[i] << endl;
        }


        cout << "\nUsing Simpson's One Third Rule \n";
        cout << "====================================\n";
        cout << "I = (h/3) * [y0 + yn + 4*(sum of odd number] + 2*(sum of even number)\n";
        cout << "h = (b-a)/n = " << h << "\n ";


        cout << "Intervals = " << n << endl;

        cout << "====================================\n";

        cout << left << setw(15) << "Iteration"
             << setw(15) << "X"
             << setw(15) << "FX" << endl;

        for (int i = 0; i <= n; i++)
        {
            cout << left << setw(15) << i + 1
                 << setw(15) << x[i]
                 << setw(15) << fx[i] << endl;
        }
        cout<<"\nAnswer = "<<result ;
    }
    ~display()
    {
        delete[] x;
        delete[] fx;
    }

};
int main()
{
    display simpson;

    simpson.hValue();
    simpson.inputArray();
    simpson.findFx();
    simpson.findAnswer();
    simpson.displayAnswer();
}