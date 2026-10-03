#include<iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    char *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void Push(char val)
    {
        if(top < size - 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack Overflow." << endl;
        }
    }

    void Pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow." << endl;
        }
    }

    char Peek()
    {
        if(top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack underflow." << endl;
            return '\0';
        }
    }

    bool Isempty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~Stack()
    {
        delete [] arr;
    }
};

int Precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }

    if(op == '*' || op == '/' || op == '%')
    {
        return 2;
    }

    return 0;
}

bool IsOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char infix[100];
    char postfix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    Stack s(100);

    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9'))
        {
            postfix[j] = ch;
            j++;
        }

        else if(ch == '(')
        {
            s.Push(ch);
        }

        else if(ch == ')')
        {
            while(!s.Isempty() && s.Peek() != '(')
            {
                postfix[j] = s.Peek();
                j++;
                s.Pop();
            }

            if(!s.Isempty())
            {
                s.Pop();
            }
        }

        else if(IsOperator(ch))
        {
            while(!s.Isempty() &&
                  s.Peek() != '(' &&
                  Precedence(s.Peek()) >= Precedence(ch))
            {
                postfix[j] = s.Peek();
                j++;
                s.Pop();
            }

            s.Push(ch);
        }
    }

    while(!s.Isempty())
    {
        postfix[j] = s.Peek();
        j++;
        s.Pop();
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
