#include <iostream>
#include <string>
using namespace std;

int main()
{
    float temp[3][7];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter 7 temperatures for city " << i + 1 << ":" << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "  Day " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }

    cout << "\nTemperature Details:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "City " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++)
        {
            cout << "  Day " << j + 1 << ": " << temp[i][j] << " °C" << endl;
        }
    }

    cout << "\nAverage Temperatures:\n";
    for (int i = 0; i < 3; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < 7; j++)
        {
            sum += temp[i][j];
        }
        float avg = sum / 7.0;
        cout << "  City " << i + 1 << " average: " << avg << " °C" << endl;
    }

    return 0;
}