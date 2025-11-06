#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // Maximum size of stack

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        if (top == MAX - 1)
        {
            cout << "Stack overflow!" << endl;
        }
        else
        {
            arr[++top] = c;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
        }
        else
        {
            top--;
        }
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

bool isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr)
{
    Stack s;

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isEmpty() || !isMatchingPair(s.peek(), ch))
                return false;
            s.pop();
        }
    }

    return s.isEmpty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced expression" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
