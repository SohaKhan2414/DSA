#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int val)
{
    data=val;
    next=NULL;
}
};
class SinglyList{
public:
Node*head;
Node*tail;
SinglyList()
{
    head=NULL;
    tail=NULL;
}
void PushFront(int val)
{
    Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
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
        tail->next=newNode;
        tail=newNode;
    }
}
void popFront()
{
    if(head==NULL)
    {
        return;
    }
    Node*temp=head;
    if(head==tail)
    {
        head=tail=NULL;
        delete temp;
    }
    else
    {
    head=head->next;
    delete temp;    
    }
}
void popBack()
{ 
    if(head==NULL)
        return;

    if(head==tail)
    {
        delete head;
        head=tail=NULL;
        return;
    }
    Node*temp=head;
    while(temp->next!=tail)
    {
    temp=temp->next;

    }
    temp->next=NULL;
    delete tail;
    tail=temp;
}
void InsertAtAnyPosition(int val,int pos)
{   
    Node*newNode=new Node(val);
    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
    if(tail==NULL)
        tail=newNode;

        return;
    }
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
       temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    if(newNode->next==NULL)
    {
        tail=newNode;
    }
    
}
void DeleteAtAnyPosition(int pos)
{
    if(pos==1)
    {
        Node*temp=head;
        head=head->next;
    if(head==NULL)
    {
        tail=NULL;
    }
        delete temp;
        return;
    }
   
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    Node*del=temp->next;
    temp->next=del->next;
    if(del==tail)
    {
        tail=temp;
    }
    delete del;
}
void Search(int val)
{
    Node*temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            cout<<"Value found at "<<pos<<" position "<<endl;
            return;
        }
        temp=temp->next;
        pos++;

    }
    cout<<"Not found."<<endl;
}
void display()
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main()
{
SinglyList sl;
sl.PushFront(5);
sl.PushFront(2);
sl.PushFront(1);
sl.display();
sl.PushBack(9);
sl.display();
sl.popFront();
sl.display();
sl.popBack();
sl.display();
sl.InsertAtAnyPosition(10,2);
sl.display();
sl.DeleteAtAnyPosition(3);
sl.display();
sl.Search(1);
sl.display();
}
