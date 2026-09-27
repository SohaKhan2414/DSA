#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int data;
Node(int val)
{
    data=val;
    next=NULL;
}
};
class CircularLinkedList{
public:
Node*head;
Node*tail;
CircularLinkedList()
{
    head=NULL;
    tail=NULL;

}
void pushFront(int val)
{   
    Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        tail->next=head;
        return;
    }
    newNode->next=head;
    head=newNode;
    tail->next=head;
}
void pushBack(int val)
{
    Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        tail->next=head;
        return;
    }
    newNode->next=head;
    tail->next=newNode;
    tail=newNode;
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
        delete head;
        head=tail=NULL;
        return;
    }
        Node*temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=head;
        delete tail;
        tail=temp;
}
void InsertAtAnyPosition(int val,int pos)
{   
    Node*newNode=new Node(val);
    if(pos==1)
    {
        if(head==NULL)
        {
            head=tail=newNode;
            tail->next=head;
            return;
        }
        newNode->next=head;
        head=newNode;
        tail->next=head;
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
        cout<<"Not Found."<<endl;
        return;
    }
    Node*temp=head;
    int pos=1;
    do
    {
    if(temp->data==val)
    {
        cout<<"value found at position "<<pos<<endl;
        return;
    }
    temp=temp->next;
    pos++;
    } while (temp!=head);
    cout<<"Not Found."<<endl;    
}
void Display()
{
    if(head==NULL)
    {
        cout<<endl;
        return;
    }
    Node*temp=head;
    do{
       cout<< temp->data<<" ";
       temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
};
int main()
{
CircularLinkedList cll;
cll.pushFront(1);
cll.pushFront(2);
cll.pushFront(3);
cll.Display();
cll.pushBack(4);
cll.Display();
cll.popFront();
cll.Display();
cll.popBack();
cll.Display();
cll.InsertAtAnyPosition(0,2);
cll.Display();
cll.DeleteAtAnyPosition(3);
cll.Display();
cll.Search(2);
return 0;
}