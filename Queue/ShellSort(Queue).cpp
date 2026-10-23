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

    void shellAscending()
    {
        int temp;

        for(int gap=(rear-front+1)/2;gap>=1;gap=gap/2)
        {
            for(int j=front+gap;j<=rear;j++)
            {
                for(int i=j-gap;i>=front;i=i-gap)
                {
                    if(arr[i+gap]>arr[i])
                    {
                        break;
                    }
                    else
                    {
                        temp=arr[i];
                        arr[i]=arr[i+gap];
                        arr[i+gap]=temp;
                    }
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

    q.shellAscending();

    cout<<"Sorted Queue: ";
    q.display();

    return 0;
}