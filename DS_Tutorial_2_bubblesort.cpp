#include <iostream>
using namespace std;
int main()
{
    int n, i;
    int temp, j;
    int player[12];
    cout << "Enter the no of players:";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter score of player:" << i + 1 << endl;
        cin >> player[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (player[j] > player[j + 1])
            {
                temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }

        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << player[k] << " ";
        }
        cout << endl;
    }

    cout << "\nFinal sorted list is:" << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Player " << i + 1 << " sorted is " << player[i] << endl;
    }
    return 0;
}