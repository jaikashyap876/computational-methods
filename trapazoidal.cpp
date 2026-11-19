#include <iostream>
#include<iomanip>
using namespace std;
void inputArray(double x[], int n)
{
    cout << "Enter array elements: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> x[i];
    }
}

double function(double x)
{
    return x * x * x;
}

double trapezoidalFormula(double fx[], int n, int a, int b)
{
    double h = (double)(b - a) / n;
    double answer = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            answer += fx[i];
        else
            answer += 2 * fx[i];
    }

    answer = answer * (h / 2);
    return answer;
}
void display(double fx[], double x[], int n,
             double result, string equation)
{
cout << "Trapezoidal Rule Formula: " << endl;
cout << "I = (h/2) * [y0 + yn + 2(y1 + y2 + ... + yn-1)]" << endl;
cout << "h = (b-a)/n" << endl;
    cout<<"Using trapazoidal Rule "<<endl ;
    cout<<"===================================="<<endl;
    
    cout << "\nFunction = " << equation;
    cout << "\nIntervals = " << n;
    cout<<"\n===================================="<<endl;

    cout << "\n\n";
    cout << left << setw(15) << "Iteration"
         << setw(15) << "X"
         << setw(15) << "FX";

    for (int i = 0; i <= n; i++)
    {
        cout << "\n"
             << left << setw(15) << i + 1
             << setw(15) << x[i]
             << setw(15) << fx[i];
    }

    cout << "\n\nIntegration = " << result;
}

int main()
{
    int n, a, b;

    cout << "Enter number of intervals: ";
    cin >> n;

    cout << "Enter lower limit: ";
    cin >> a;

    cout << "Enter upper limit: ";
    cin >> b;
    cout<<"===================================="<<endl;

    double x[n + 1];
    double fx[n + 1];

    inputArray(x, n);

    for (int i = 0; i <= n; i++)
    {
        fx[i] = function(x[i]);
    }

    double result = trapezoidalFormula(fx, n, a, b);

    display(fx, x, n, result, "x^3");

    return 0;
}
