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
class List
{
public:
Node*head;
Node*tail;
List()
{
    head=NULL;
    tail=NULL;
}
void PushFront(int val)
{
    Node*newNode=new Node (val);
    if(head==NULL)
    {
    head=tail=newNode;
    return;
    }
    newNode->next=head;
    head=newNode;
}
Node* findMiddle()
{
   Node*fast=head;
   Node*slow=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
     slow=slow->next;
     fast=fast->next->next;
   } 
   return slow;
}
Node* Reversal(Node*head)
{   
    Node*prev=NULL;
    Node*next=NULL;
    Node*current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
   return prev;
}
bool PalindromeCheck()
{
   Node*middle=findMiddle();
   Node*secondhalf=Reversal(middle);
   Node*first=head;
   Node*second=secondhalf;
   while(second!=NULL)
   {
    if(first->data!=second->data)
    {
        return false;
    }
    first=first->next;
    second=second->next;
   }
   return true;
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
};
int main()
{
 List ll;
 ll.PushFront(1);
 ll.PushFront(2);
 ll.PushFront(3);
 ll.PushFront(2);
 ll.PushFront(1);
 ll.Display();
 if(ll.PalindromeCheck())
 {
    cout<<"True."<<endl;
 }
 else
 {
    cout<<"False"<<endl;
 }
 return 0;
}