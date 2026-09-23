#include<iostream>
using namespace std;

class Stack
{
public:
    char arr[100];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(char val)
    {
        top++;
        arr[top]=val;
    }

    char pop()
    {
        if(top==-1)
        {
            return '\0';
        }

        char val=arr[top];
        top--;
        return val;
    }

    char peek()
    {
        if(top==-1)
        {
            return '\0';
        }

        return arr[top];
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

    cout<<"Enter brackets: ";
    cin>>exp;

    for(int i=0; exp[i]!='\0'; i++)
    {
        char current=exp[i];

        if(current=='(' || current=='[' || current=='{')
        {
            s.push(current);
        }
        else if(current==')' || current==']' || current=='}')
        {
            if(s.Isempty())
            {
                cout<<"Not Balanced"<<endl;
                return 0;
            }

            char top=s.pop();

            if((current==')' && top!='(') ||
               (current==']' && top!='[') ||
               (current=='}' && top!='{'))
            {
                cout<<"Not Balanced"<<endl;
                return 0;
            }
        }
    }

    if(s.Isempty())
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not Balanced"<<endl;
    }

    return 0;
}