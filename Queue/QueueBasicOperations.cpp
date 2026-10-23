#include<iostream>
using namespace std;
class Queue{
public:
int size;
int *arr;
int front;
int rear;
Queue(int size)
{
    this->size=size;
    arr=new int[size];
    front=-1;
    rear=-1;
}
void Enqueue(int val)
{
    if(rear==size-1)
    {
        cout<<"Queue is Full."<<endl;
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    arr[rear]=val;
}
void Dequeue()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue is empty."<<endl;
        return;
    }
    front++;
}
void Peek()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue is empty."<<endl;
        return;
    }
   cout<< arr[front];
}
void Display()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue is empty."<<endl;
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }

}

};
int main()
{
 Queue Q(3);
 cout<<"Queue: "<<endl;
 Q.Enqueue(1);
 Q.Enqueue(2);
 Q.Enqueue(3);
 Q.Display();
 cout<<endl;
 cout<<"After Dequeue: "<<endl;
 Q.Dequeue();
 Q.Display();
 cout<<endl;
 cout<<"Top element: "<<endl;
 Q.Peek();
 return 0;
}