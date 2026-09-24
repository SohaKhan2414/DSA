#include<iostream>
using namespace std;
class Stack{
public:
int top;
int *arr;
int size;
  
   Stack(int size)
{
    this->size=size;
    arr=new int[size];
    top=-1;
}

void push(int val)
{
    if(top==size-1)
{
        cout<<"Overflow"<<endl;
}
top++;
arr[top]=val;

}
int pop()
{
    if(top==-1)
    {
        return -1;
    }
    int value=arr[top];
    top--;
    return value;
}
bool Isempty()
{
    
    return top==-1;
}
~Stack()
{
    delete []arr;
}
};
int main()
{
string num1,num2;
cout<<"Enter number 1:"<<endl;
cin>>num1;
cout<<"Enter number 2:"<<endl;
cin>>num2;
Stack ss1(num1.length());
Stack ss2(num2.length());
Stack result(num1.length()+num2.length());
for(int i=0;i<num1.length();i++)
{
    ss1.push(num1[i]-'0');
}
for(int i=0;i<num2.length();i++)
{
    ss2.push(num2[i]-'0');
}
int carry=0;
while(!ss1.Isempty()||!ss2.Isempty())
{
    int digit1=0;
    int digit2=0;
    if(!ss1.Isempty())
    {
        digit1=ss1.pop();
    }
    if(!ss2.Isempty())
    {
        digit2=ss2.pop();
    }
    int sum=digit1+digit2+carry;
    int digit=sum%10;
    result.push(digit);
    carry=sum/10;

}
if(carry>0)
{
    result.push(carry);
}
cout<<"Sum: "<<endl;
while(!result.Isempty())
{
    cout<<result.pop();
}
return 0;
};
