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
    int pass=1;
    int comparisons=0;
    int swaps=0;
    while(current->next!=NULL)
    {
        Node*temp=head;
        while(temp->next!=NULL)
        {   
            comparisons++;
            if(temp->data>temp->next->data)
            {
                int x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;
                swaps++;
            }
            temp=temp->next;
        }
        cout<<"Pass: "<<pass<<endl;
        pass++;
        current=current->next;
    }
    cout<<"No of swaps: "<<swaps<<endl;
    cout<<"Total Comparisons: "<<comparisons<<endl;
}
};
int main()
{
    DoublyLinkedList ll;
    ll.PushBack(5);
    ll.PushBack(4);
    ll.PushBack(1);
    ll.PushBack(2);
    ll.Display();
    ll.Sort();
    ll.Display();
    return 0;
}