#include<iostream>
using namespace std;

class Stack
{
public:
    int arr[100];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(int val)
    {
        top++;
        arr[top]=val;
    }

    int pop()
    {
        if(top==-1)
        {
            return -1;
        }

        int val=arr[top];
        top--;
        return val;
    }

    bool Isempty()
    {
        return top==-1;
    }
};

int main()
{
    Stack s;
    string exp;

    cout<<"Enter postfix expression: ";
    cin>>exp;

    for(int i=0; exp[i]!='\0'; i++)
    {
        char current=exp[i];

        if(current>='0' && current<='9')
        {
            s.push(current-'0');
        }
        else
        {
            int b=s.pop();
            int a=s.pop();

            if(current=='+')
            {
                s.push(a+b);
            }
            else if(current=='-')
            {
                s.push(a-b);
            }
            else if(current=='*')
            {
                s.push(a*b);
            }
            else if(current=='/')
            {
                s.push(a/b);
            }
        }
    }

    cout<<"Answer = "<<s.pop()<<endl;

    return 0;
}
