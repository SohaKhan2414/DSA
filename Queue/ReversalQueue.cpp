#include<iostream>
using namespace std;

class Queue
{
public:
    int arr[100];
    int front;
    int rear;

    Queue()
    {
        front=0;
        rear=0;
    }

    void Enqueue(int val)
    {
        arr[rear]=val;
        rear++;
    }

    int Dequeue()
    {
        int val=arr[front];
        front++;
        return val;
    }

    bool Isempty()
    {
        return front==rear;
    }
};

class Stack
{
public:
    int arr[100];
    int top;

    Stack()
    {
        top=-1;
    }

    void push(int val)
    {
        top++;
        arr[top]=val;
    }

    int pop()
    {
        int val=arr[top];
        top--;
        return val;
    }

    bool Isempty()
    {
        return top==-1;
    }
};

int main()
{
    Queue q;
    Stack s;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);

    while(!q.Isempty())
    {
        s.push(q.Dequeue());
    }

    while(!s.Isempty())
    {
        q.Enqueue(s.pop());
    }

    while(!q.Isempty())
    {
        cout<<q.Dequeue()<<" ";
    }

    return 0;
}
