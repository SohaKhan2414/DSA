#include<iostream>
using namespace std;

class CircularQueue
{
public:
    int front;
    int rear;
    int size;
    int* arr;

    CircularQueue(int s)
    {
        size=s;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

    bool isEmpty()
    {
        return front==-1;
    }

    bool isFull()
    {
        return (rear+1)%size==front;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }

        if(isEmpty())
        {
            front=0;
        }

        rear=(rear+1)%size;
        arr[rear]=x;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
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

    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

        int i=front;

        while(true)
        {
            cout<<arr[i]<<" ";

            if(i==rear)
            {
                break;
            }

            i=(i+1)%size;
        }

        cout<<endl;
    }

    int linearSearch(int key)
    {
        if(isEmpty())
        {
            return -1;
        }

        int i=front;

        while(true)
        {
            if(arr[i]==key)
            {
                return i;
            }

            if(i==rear)
            {
                break;
            }

            i=(i+1)%size;
        }

        return -1;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(50);
    q.enqueue(20);
    q.enqueue(30);

    cout<<"Queue: ";
    q.display();

    int key=20;

    int result=q.linearSearch(key);

    if(result!=-1)
    {
        cout<<"Element found at index "<<result<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }

    return 0;
}