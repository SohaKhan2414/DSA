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
        head->prev=newNode;
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
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}
void PopFront()
{
    if(head==NULL)
    {
        return;
    }
    Node*temp=head;
    if(head==tail)
    {
        head=tail=NULL;

    }
    else
    {
        head=head->next;
        head->prev=NULL;

    }
    delete temp;
}
void PopBack()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)
    {
        delete head;
        head=tail=NULL;
        return;
    }
    Node*temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;

}
void InsertAtAnyPosition(int pos,int val)
{
    Node*newNode=new Node(val);
    if(pos==1)
    {
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }
    else
    {
        tail=newNode;

    }
    temp->next=newNode;
}
void DeleteAtAnyPosition(int pos)
{
    if(head==NULL)
    {
        return;
    }
    if(pos==1)
    {
        PopFront();
        return;
    }
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
  
    if(temp->next==tail)
    {
        PopBack();
        return;
    }
    Node*del=temp->next;
    temp->next=del->next;
    del->next->prev=temp;
    delete del;
}
void Search(int val)
{
    Node*temp=head;
    int position=1;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            cout<<"Value found at "<<position<<" position "<<endl;
            return;
        }
        temp=temp->next;
        position++;
    }
    cout<<"Not Found."<<endl;
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
};
int main()
{
  DoublyLinkedList Dll;
  Dll.PushFront(3);
  Dll.Display();
  Dll.PushFront(2);
  Dll.Display();
  Dll.PushFront(4);
  Dll.Display();
  Dll.PushBack(7);
  Dll.Display();
  Dll.PopFront();
  Dll.Display();
  Dll.PopBack();
  Dll.Display();
  Dll.InsertAtAnyPosition(3,1);
  Dll.Display();
  Dll.DeleteAtAnyPosition(2);
  Dll.Display();
  Dll.Search(4);
  Dll.Display();
  return 0;
}