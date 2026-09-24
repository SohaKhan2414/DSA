#include<iostream>
using namespace std;
class TwoStacks{
public:
int top1,top2;
int *arr;
int size;
TwoStacks(int size)
{
this->size=size;
arr=new int[size];
top1=-1;
top2=size;
}
void push1(int val)
{
    if(top1<size-1)
    {
        top1++;
        arr[top1]=val;
    }else
    {
        cout<<"Stack overflow.";
    }
}
void pop1()
{
    if(top1>=0)
    {
        top1--;
    }else
    {
        cout<<"Stack underflow."<<endl;
    }
}
int peek1()
{
if(top1>=0)
{
    return arr[top1];
}else
{
    cout<<"Stack is empty."<<endl;
    return -1;
}
}
bool IsEmpty1()
{
if(top1==-1)
{
    return true;
}else
{
    return false;
}
}
void push2(int val)
{
    if(top1+1<top2)
    {
        top2--;
        arr[top2]=val;
    }
    else
    {
        cout<<"Stack overflow."<<endl;
    }
}
void pop2()
{ 
    if(top2<size)
    {
top2++;

    }
    else
    {
cout<<"Stack underflow"<<endl;
    }}
    int peek2()
    {
        if(top2<size)
        {
            return arr[top2];
        }else
        {
            return -1;
        }
    }
bool Isempty2()
{
    if(top2==size)
    {
return true;
    }else
    {
        return false;
    }
}

};
int main()
{
TwoStacks ss(6);
ss.push1(5);
ss.push1(3);
ss.push1(6);
cout << "Stack 1 top: " << ss.peek1() << endl;
ss.pop1();
 cout << "Stack 1 top after pop: " << ss.peek1() << endl;

ss.push2(4);
ss.push2(1);
cout << "Stack 2 top: " << ss.peek2() << endl;
ss.pop2();
cout << "Stack 2 top: " << ss.peek2() << endl;
if(ss.IsEmpty1())
{
    cout << "Stack 1 is empty." << endl;
}
else
{
    cout << "Stack 1 is not empty." << endl;
}

if(ss.Isempty2())
{
    cout << "Stack 2 is empty." << endl;
}
else
{
    cout << "Stack 2 is not empty." << endl;
}


}
