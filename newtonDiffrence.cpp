#include <iostream>
using namespace std;

class inputValue
{
protected:
    int n;
    double findX;
    double x[20], y[20];

public:
    inputValue()
    {
        cout << "Enter the length: ";
        cin >> n;

        cout << "Enter x: ";
        cin >> findX;
    }

    void inputArray()
    {
        cout << "Enter x values:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        cout << "Enter y values:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }
    }
};
class deltaY : public inputValue
{
protected:
    double deltaYvalue[20][20];

public:
    void deltaCalculation()
    {
        for (int j = 0; j < n - 1; j++)
        {
            deltaYvalue[j][0] =
                (y[j + 1] - y[j]) / (x[j + 1] - x[j]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                deltaYvalue[j][i] =
                    (deltaYvalue[j + 1][i - 1] -
                     deltaYvalue[j][i - 1]) /
                    (x[j + i + 1] - x[j]);
            }
        }
    }
    void display()
    {
        cout << " x Cordinates " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << " " << x[i];
        }
        cout << endl
             << " y Cordinates " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << " " << y[i];
        }
        cout << endl
             << "Delta Y :\n";
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 + i; j++)
            {
                cout << "Delta Y [" << i << "][ " << j << "] : " << deltaYvalue[j][i] << "  ";
            }
            cout << endl;
        }
    }
};
class interpolation : public deltaY
{
public:
    void calculateResult()
    {
        double answer = y[0];
        double product = 1;
        for (int i = 0; i < n - 1; i++)
        {
            product = product * (findX - x[i]);

            answer = answer +
                     product * deltaYvalue[0][i];
        }
        cout << "\nInterpolated value = " << answer;
    }
};

int main()
{
    interpolation obj;
    obj.inputArray();
    obj.deltaCalculation();
    obj.display();
    obj.calculateResult();
    return 0;
}
