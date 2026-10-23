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

    int linearSearch(int key)
    {
        for(int i=front;i<=rear;i++)
        {
            if(arr[i]==key)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Queue q(6);

    q.enqueue(60);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(10);
    q.enqueue(40);
    q.enqueue(30);

    cout<<"Queue: ";
    q.display();

    int key;
    cout<<"Enter value to search: ";
    cin>>key;

    int result=q.linearSearch(key);

    if(result!=-1)
    {
        cout<<"Value found at index: "<<result<<endl;
    }
    else
    {
        cout<<"Value not found"<<endl;
    }

    return 0;
}