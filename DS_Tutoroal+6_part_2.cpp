#include <iostream>
using namespace std;

class CircularQueue
{
    int front, rear, capacity;
    string *queue;

public:
    CircularQueue(int size)
    {
        capacity = size;
        queue = new string[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == capacity - 1) || ((rear + 1) % capacity == front);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(string jobName)
    {
        if (isFull())
        {
            cout << "Printer queue is full! Cannot add job: " << jobName << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = jobName;
        cout << "Print job '" << jobName << "' added to the queue.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Printer queue is empty! No job to process.\n";
            return;
        }
        cout << "Processing and removing print job: " << queue[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Printer queue is empty.\n";
            return;
        }
        cout << "Current print queue: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "------ Printer Spooler ------";
    cout << "\nEnter printer queue capacity: ";
    cin >> size;

    CircularQueue printer(size);
    int choice;
    string jobName;

    do
    {
        cout << "\n1. Add Print Job\n2. Process Print Job\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter print job name: ";
            cin >> jobName;
            printer.enqueue(jobName);
            break;
        case 2:
            printer.dequeue();
            break;
        case 3:
            printer.display();
            break;
        case 4:
            cout << "Exiting printer spooler.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}