#include<iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void Push(int val)
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

    int Peek()
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
int main()
{
    char postfix[100];
    cout<<"Enter Postfix expression: "<<endl;
    cin>>postfix;
    Stack s(100);
    for(int i=0;postfix[i]!='\0';i++)
    {
        char ch=postfix[i];
        if(ch>='0'&&ch<='9')
        {
            int num=ch-'0';
            s.Push(num);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
        {
            int first=s.Peek();
            s.Pop();
            int second=s.Peek();
            s.Pop();
            int result;
            if(ch=='+')
            {
            result=second+first;
            }
            else if(ch=='-')
            {
            result=second-first;
            }
            else if(ch=='*')
            {
            result=second*first;
            }
            else if(ch=='/')
            {
            result=second/first;
            }
            else 
            {
            result=second%first;
            }
            s.Push(result);
        }
    }
    cout<<"Answer: "<<s.Peek()<<endl;

    return 0;
}
