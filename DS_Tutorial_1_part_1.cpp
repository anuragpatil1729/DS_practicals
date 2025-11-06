#include <iostream>
#include <string>
using namespace std;

void input(float rainfall[3][4])
{
    string cities[] = {"city 1", "city 2", "city 3"};
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter rainfall for " << cities[i] << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << "Month " << j + 1 << ": ";
            cin >> rainfall[i][j];
        }
    }
}

void averagerainfall(float rainfall[3][4], float avgrainfall[3])
{
    for (int i = 0; i < 3; i++)
    {
        float sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += rainfall[i][j];
        }
        avgrainfall[i] = sum / 4.0;
    }
}

void display(float rainfall[3][4], float avgrainfall[3])
{
    cout << "\nRainfall Data\n";
    cout << "City\tMonth1\tMonth2\tMonth3\tMonth4\tAverage\n";

    string cities[] = {"city 1", "city 2", "city 3"};

    for (int i = 0; i < 3; i++)
    {
        cout << cities[i] << "\t";
        for (int j = 0; j < 4; j++)
        {
            cout << rainfall[i][j] << "\t";
        }
        cout << avgrainfall[i] << endl;
    }
}

int main()
{
    float new_rainfall[3][4];
    float new_avgrainfall[3];

    input(new_rainfall);
    averagerainfall(new_rainfall, new_avgrainfall);
    display(new_rainfall, new_avgrainfall);

    return 0;
}