#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int data;
Node(int val)
{
    next=NULL;
    data=val;
}
};
class List{
public:
Node*head;
Node*tail;
List()
{
    head=NULL;
    tail=NULL;
}
void pushBack(int val)
{   
    Node*newNode=new Node(val);
    if(head==NULL)
    {
     head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}
void Display()
{
    Node*temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<" -> ";
    temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
void DetectRemoveLoop()
{
   Node*slow=head;
   Node*fast=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
    {
    cout<<"Loop Detected."<<endl;
    break;
    }
   }
   if(slow!=fast)
   {
    cout<<"No Loop Detected."<<endl;
    return;
   }
   slow=head;
   
   while(slow!=fast)
   {
    slow=slow->next;
    fast=fast->next;
   }
   
   Node*loopstart=slow;
   cout<<"Loop starting node: "<<loopstart->data<<endl;
   Node*temp=loopstart;
   while(temp->next!=loopstart)
   {
    temp=temp->next;
   }
   temp->next=NULL;
   tail=temp;
}
};
int main()
{
List ll;
ll.pushBack(1);
ll.pushBack(2);
ll.pushBack(3);
ll.pushBack(4);
ll.pushBack(5);
ll.pushBack(6);
Node*temp=ll.head;
for(int i=1;i<3;i++)
{
    temp=temp->next;
}
ll.tail->next=temp;
ll.DetectRemoveLoop();
ll.Display();
return 0;
}