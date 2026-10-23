#include<iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int size;
    int* arr;

    Queue(int s)
    {
        size=s;
        front=0;
        rear=-1;
        arr=new int[size];
    }

    bool isFull()
    {
        return rear==size-1;
    }

    bool isEmpty()
    {
        return rear<front;
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Queue Full"<<endl;
            return;
        }

        rear++;
        arr[rear]=x;
    }

    int dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }

        return arr[front++];
    }

    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

    void bubbleAscending()
    {
        for(int i=front;i<rear;i++)
        {
            for(int j=front;j<rear-(i-front);j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
};

int main()
{
    Queue q(5);

    q.enqueue(60);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(10);
    q.enqueue(40);

    cout<<"Original Queue: ";
    q.display();

    q.bubbleAscending();

    cout<<"Sorted Queue: ";
    q.display();

    return 0;
}