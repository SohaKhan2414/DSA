#include<iostream>
using namespace std;
class Node{
public:
Node*prev;
Node*next;
int data;
Node(int val)
{
    data=val;
    prev=NULL;
    next=NULL;
}

};
class DoublyLinkedList{
public:
Node*head;
Node*tail;
DoublyLinkedList()
{
    head=NULL;
    tail=NULL;
}
void PushBack(int val)
{
    Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}
void Display()
{
    Node*temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}
void Sort()
{
    Node*current=head;
    int comparisons=0;
    int swaps=0;
    int pass=1;
    while(current!=NULL)
    {
        Node*min=current;
        Node*temp=current->next;
        while(temp!=NULL)
        {
            comparisons++;
            if(temp->data<min->data)
            {
                min=temp;
            }
            temp=temp->next;
        }
        if(min!=current)
        {
        int x=current->data;
        current->data=min->data;
        min->data=x;
        swaps++;
        }
        cout<<"Number of pass: "<<pass<<endl;
        pass++;
        current=current->next;
    }
    cout<<"Number of comparisons: "<<comparisons<<endl;
    cout<<"Number of swaps: "<<swaps<<endl;
}
};
int main()
{
    DoublyLinkedList dll;
    dll.PushBack(5);
    dll.PushBack(4);
    dll.PushBack(1);
    dll.PushBack(2);
    dll.Display();
    dll.Sort();
    dll.Display();
    return 0;
}