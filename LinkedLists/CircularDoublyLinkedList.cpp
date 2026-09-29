#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node*prev;
Node(int val)
{
    data=val;
    next=NULL;
    prev=NULL;
}

};
class CircularDoublyLinkedList{
public:
Node*head;
Node*tail;
CircularDoublyLinkedList()
{
    head=NULL;
    tail=NULL;
}
void pushFront(int val)
{   Node*newNode=new Node(val);
    if(head==NULL)
    {
    head=tail=newNode;
    head->next=head;
    head->prev=head;
    return ;
    }
    newNode->next=head;
    newNode->prev=tail;
    head->prev=newNode;
    tail->next=newNode;
    head=newNode;
}
void pushBack(int val)
{
    Node*newNode=new Node(val);
    if(head==NULL)
    {
    head=tail=newNode;
    head->next=head;
    head->prev=head;
    return ;
    }
    else
    {
        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        head->prev=newNode;
        tail=newNode;
    }
}
void popFront()
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
    Node*temp=head;
    head=head->next;
    head->prev=tail;
    tail->next=head;
    delete temp;
}
void popBack()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)
    {
        delete tail;
        head=tail=NULL;
        return;
    }
    Node*temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
    delete temp;
}
void InsertAtAnyPosition(int val,int pos)
{
    Node*newNode=new Node(val);
    if(pos==1)
    {
        if(head==NULL)
        {
            head=tail=newNode;
            head->next=head;
            head->prev=head;
            return;
        }
        newNode->next=head;
        newNode->prev=tail;
        head->prev=newNode;
        tail->next=newNode;
        head=newNode;
        return;

    }
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
    temp=temp->next;
    if(temp==head)
    {
        return;
    }

    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
    if(temp==tail)
    {
        tail=newNode;
    }    
}
void DeleteAtAnyPosition(int pos)
{
    if(head==NULL)
    {
        return;
    }
    if(pos==1)
    {
        popFront();
        return;
    }
    Node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==head)
       {
        return;
       }

    }
    
    Node*del=temp->next;
    if(del==head)
    {
        return;
    }
    temp->next=del->next;
    del->next->prev=temp;
    if(del==tail)
    {
        tail=temp;
    }
    delete del;
}
void Search(int val)
{
    if(head==NULL)
    {
        cout<<"Not found.";
        return;
    }
    Node*temp=head;
    int pos=1;
    do{
        if(temp->data==val)
        {
            cout<<"Value found at position "<<pos<<endl;
            return;
        }
        temp=temp->next;
        pos++;
      }while(temp!=head);
    cout<<"Not Found."<<endl;
}
void Display()
{
    if(head==NULL)
    {
        return;
    }
    Node*temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);

    cout<<endl;
}
};
int main()
{
    CircularDoublyLinkedList list;

    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    list.Display();

    list.pushBack(4);
    list.Display();

    list.popFront();
    list.Display();
    list.popBack();
    list.Display();

    list.InsertAtAnyPosition(0,2);
    list.Display();
    list.DeleteAtAnyPosition(3);
    list.Display();
    list.Search(2);

    list.Display();

    return 0;

}