#include <iostream>
using namespace std;

int main()
{
    int n;
    int cards[100];

    cout << "Enter number of cards: ";
    cin >> n;

    cout << "\nEnter the card values:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Card " << i + 1 << ": ";
        cin >> cards[i];
    }

    cout << "\nA\n";
    cout << "Organizing Cards Using Insertion Sort:\n\n";

    for (int i = 1; i < n; i++)
    {
        int key = cards[i];
        int j = i - 1;

        while (j >= 0 && cards[j] > key)
        {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;

        cout << "After inserting card " << key << ": ";
        for (int k = 0; k <= i; k++)
        {
            cout << cards[k];
        }
        cout << "\n";
    }

    cout << "\nFinal Sorted Hand\n";
    for (int i = 0; i < n; i++)
    {
        cout << cards[i] << " ";
    }
    cout << "\n";

    return 0;
}