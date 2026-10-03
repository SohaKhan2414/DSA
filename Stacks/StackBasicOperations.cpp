#include<iostream>
using namespace std;
class Stack{
public:
int *arr;
int top;
int size;
Stack(int size)
{   
    this->size=size;
    arr=new int[size];
    top=-1;
}
void Push(int val)
{
    if(top<size-1)
    {
        top++;
        arr[top]=val;
    }
    else
    {
        cout<<"Stack Overflow."<<endl;

    }
}
void Pop()
{
    if(top>=0)
    {
        top--;
    }
    else
    {
        cout<<"Stack underflow."<<endl;
    }
}
int Peek()
{
    if(top>=0)
    {
        return arr[top];
    }
    else
    {
        cout<<"Stack is empty."<<endl;
        return -1;
    }
}
bool Isempty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Isfull()
{
    if(top>=size-1)
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
  Stack s(3);
  s.Push(1);
  s.Push(2);
  s.Push(3);
  cout<<"Top element: "<<s.Peek()<<endl;
  s.Pop();
  cout<<"Top element: "<<s.Peek()<<endl;
  if(s.Isempty())
  {
   cout<<"Stack empty."<<endl;
  }
  else
  {
    cout<<"Stack not empty."<<endl;
  }
  if(s.Isfull())
  {
   cout<<"Stack is full. "<<endl;
  }
  else
  {
    cout<<"Stack is empty."<<endl;
  }
  return 0;
}