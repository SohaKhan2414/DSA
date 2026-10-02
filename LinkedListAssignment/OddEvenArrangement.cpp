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
Node*oddhead;
Node*evenhead;
Node*oddtail;
Node*eventail;
Node*head;
Node*tail;
List()
{
    oddhead=NULL;
    evenhead=NULL;
    oddtail=NULL;
    eventail=NULL;
    head=NULL;
    tail=NULL;
}
void OddEven()
{
Node*temp=head;
while (temp!=NULL)
{   Node*nextnode=temp->next;
    if(temp->data%2!=0)
    {
       if(oddhead==NULL)
       {
        oddhead=oddtail=temp;
       }
       else
       {
        oddtail->next=temp;
        oddtail=temp;
       }
    }
    else
    {
        if(evenhead==NULL)
        {
            evenhead=eventail=temp;
        }
        else{
            eventail->next=temp;
            eventail=temp;
        }
    }
     temp=nextnode;
}
if(oddtail!=NULL)
{
    oddtail->next=evenhead;
}
if(eventail!=NULL)
{
    eventail->next=NULL;
}
head=oddhead;
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
  cout<<temp->data<<" - > ";
  temp=temp->next;
 }
 cout<<"NULL";
 cout<<endl;
}
};
int main()
{
  List l;
  l.pushBack(2);
  l.pushBack(4);
  l.pushBack(1);
  l.pushBack(3);
  l.pushBack(5);
  l.pushBack(7);
  l.pushBack(6);
  l.OddEven();
  l.Display();
  return 0;

}