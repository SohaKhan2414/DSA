#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Queue
{
    Node* front;
    Node* rear;

public:

    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    bool Isempty()
    {
        return front==NULL;
    }

    void Enqueue(int val)
    {
        Node* newnode=new Node(val);

        if(front==NULL)
        {
            front=newnode;
            rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }

    int Dequeue()
    {
        if(front==NULL)
        {
            cout<<"Empty"<<endl;
            return -1;
        }

        int ans=front->data;
        Node* temp=front;

        front=front->next;

        if(front==NULL)
        {
            rear=NULL;
        }

        delete temp;

        return ans;
    }

    int Front()
    {
        if(front==NULL)
        {
            return -1;
        }

        return front->data;
    }

    ~Queue()
    {
        while(front!=NULL)
        {
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    }
};