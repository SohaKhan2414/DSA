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
        char val=arr[top];
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
    string str;

    cout<<"Enter string: ";
    cin>>str;

    for(int i=0; str[i]!='\0'; i++)
    {
        s.push(str[i]);
    }

    while(!s.Isempty())
    {
        cout<<s.pop();
    }

    return 0;
}