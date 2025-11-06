#include <iostream>
#include <string>
using namespace std;

#define MAX 100

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
        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

// Function to define operator precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string s)
{
    Stack st;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Operand
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
        {
            result += c;
        }

        // Opening bracket
        else if (c == '(')
        {
            st.push(c);
        }

        // Closing bracket
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                result += st.peek();
                st.pop();
            }
            if (!st.isEmpty())
                st.pop(); // Remove '('
        }

        // Operator
        else
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
            {
                if (c == '^' && precedence(st.peek()) == precedence(c))
                    break; // Right-associative
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty())
    {
        result += st.peek();
        st.pop();
    }

    return result;
}

int main()
{
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
