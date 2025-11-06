#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int priority;
    int execution_time;
    Node *next;

    Node(string name, int priority, int execution_time)
    {
        this->name = name;
        this->priority = priority;
        this->execution_time = execution_time;
        this->next = nullptr;
    }
};

void input_Task(Node *&head, Node *newTask)
{
    if (head == nullptr || newTask->priority > head->priority)
    {
        newTask->next = head;
        head = newTask;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->priority >= newTask->priority)
    {
        current = current->next;
    }
    newTask->next = current->next;
    current->next = newTask;
}

void display_task(Node *head)
{
    cout << "\nExecution Tasks:\n";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << "Task name: " << temp->name
             << " [Priority: " << temp->priority << "] "
             << "Execution Time: " << temp->execution_time << " ms\n";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout << "Enter number of tasks to schedule: ";
    cin >> n;

    Node *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        string name;
        int priority;
        int execution_time;

        cout << "\nTask " << i + 1 << " Name: ";
        cin >> name;
        cout << "Priority (higher = more important): ";
        cin >> priority;
        cout << "Execution Time (ms): ";
        cin >> execution_time;

        Node *newTask = new Node(name, priority, execution_time);
        input_Task(head, newTask);
    }

    display_task(head);

    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}