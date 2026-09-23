#include<iostream>
using namespace std;
class Queue{
int *arr;
int front;
int rear;
int size;
public:
Queue()
{
    size=100001;
    arr=new int [size];
    front=0;
    rear=0;

}
bool Isempty()
{
    if(front==rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Enqueue(int val)
{
    if(rear==size)
    {
cout<<"Full"<<endl;
    }
    else
    {
arr[rear]=val;
rear++;
    }

}
int Dequeue()
{
    int ans = -1;

    if(front==rear)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        ans=arr[front];
        arr[front]=-1;
        front++;

        if(front==rear)
        {
            front=0;
            rear=0;
        }
    }

    return ans;
}
int Front()
{
    if(front==rear)
    {
        return -1;
    }
    else
    {
        return arr[front];
    }
}

};
