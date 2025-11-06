#include <iostream>
#include <string>
using namespace std;

void Probing(int arr[], int server_size, int index, int takeVal, string req[], int reqIndex)
{
    cout << "Collision case occurred for request '" << req[reqIndex] << "'" << endl;
    while (arr[index] != 0)
    {
        index++;
        index = index % server_size;
    }
    arr[index] = takeVal;
    cout << "Request '" << req[reqIndex] << "is handled by Server " << index << endl;
}

void insertElement(int arr[], int server_size, int no_of_req, int request[], string req[])
{
    int hash_val;
    for (int i = 0; i < no_of_req; i++)
    {
        hash_val = request[i] % server_size;
        if (arr[hash_val] != 0)
        {
            Probing(arr, server_size, hash_val, request[i], req, i);
        }
        else
        {
            arr[hash_val] = request[i];
            cout << "Request '" << req[i] << "' is handled by Server " << hash_val << endl;
        }
    }

    cout << "\nPrinting the server table after hashing requests:\n";
    for (int i = 0; i < server_size; i++)
    {
        cout << "Server " << i << ": " << arr[i] << endl;
    }
}

int main()
{
    int r, s;
    cout << "Enter number of servers: ";
    cin >> s;

    int hash_val[100] = {0};

    cout << "Enter number of requests: ";
    cin >> r;

    string req[100];
    cout << "Enter " << r << " requests:" << endl;
    for (int j = 0; j < r; j++)
    {
        cin >> req[j];
    }

    int request[100];
    for (int i = 0; i < r; i++)
    {

        string digits = "";
        for (char c : req[i])
        {
            if (isdigit(c))
                digits += c;
        }
        if (!digits.empty())
        {
            request[i] = stoi(digits);
        }
        else
        {
            request[i] = i + 1;
        }
    }

    insertElement(hash_val, s, r, request, req);

    return 0;
}