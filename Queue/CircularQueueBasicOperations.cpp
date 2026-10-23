#include<iostream>
using namespace std;
class CircularQueue{
public:
int rear;
int front;
int*arr;
int size;
CircularQueue(int size)
{
    this->size=size;
    arr=new int[size];
    front=-1;
    rear=-1;
}
bool Isempty()
{
    return front==-1;
}
bool Isfull()
{
    return (rear+1)%size==front;
}
void Enqueue(int val)
{
if(Isfull())
{
    cout<<"CQ is full."<<endl;
    return;
}
if(front==-1)
{
    front=0;
    rear=0;
}
else
{
    rear=(rear+1)%size;
}
arr[rear]=val;
}
void Dequeue()
{
    if(Isempty())
    {
        cout<<"CQ is empty."<<endl;
        return;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
}
void Display()
{
    if(Isempty())
    {
        cout<<"CQ is empty."<<endl;
        return;
    }
    int i=front;
    while(true)
    {
        cout<<arr[i]<<" ";
        if(i==rear)
        break;
        i=(i+1)%size;

    }
    cout<<endl;
}
};
int main()
{
CircularQueue CQ(3);
CQ.Enqueue(1);
CQ.Enqueue(2);
CQ.Enqueue(3);
CQ.Display();
CQ.Dequeue();
CQ.Display();
return 0;
}