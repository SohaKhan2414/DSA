#include<iostream>
using namespace std;

class Stack
{
public:
    char *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new char[size];
    }

    void push(char val)
    {
        if(top == size - 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    char pop()
    {
        if(top == -1)
        {
            return -1;
        }

        char value = arr[top];
        top--;
        return value;
    }

    char peek()
    {
        if(top == -1)
        {
            return -1;
        }
        else
        {
           return arr[top];
        }
    }

    bool Isempty()
    {
        return top == -1;
    }

    int precedence(char op)
    {
        if(op == '+' || op == '-')
        {
            return 1;
        }
        else if(op == '*' || op == '/')
        {
            return 2;
        }
        else if(op == '^')
        {
            return 3;
        }

        return 0;
    }

    bool Isoperand(char ch)
    {
        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9'))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    char expression[100];
    char output[100];
    int j = 0;

    cout << "Enter infix expression: ";
    cin >> expression;

    Stack s(100);

    for(int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if(s.Isoperand(current))
        {
            output[j] = current;
            j++;
        }
        else if(current == '(')
        {
            s.push(current);
        }
        else if(current == ')')
        {
            while(!s.Isempty() && s.peek() != '(')
            {
                output[j] = s.pop();
                j++;
            }

            if(!s.Isempty())
            {
                s.pop();
            }
        }
        else
        {
            while(!s.Isempty() &&
                  s.peek() != '(' &&
                  s.precedence(s.peek()) >= s.precedence(current))
            {
                output[j] = s.pop();
                j++;
            }

            s.push(current);
        }
    }

    while(!s.Isempty())
    {
        output[j] = s.pop();
        j++;
    }

    output[j] = '\0';

    cout << "Postfix: " << output << endl;

    return 0;
}
