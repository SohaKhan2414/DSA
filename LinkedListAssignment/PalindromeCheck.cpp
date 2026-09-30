/*
A banking security system stores a user's entered PIN digits as a chain of connected boxes. Before granting access, the system must verify whether the digit sequence reads the same forwards and backwards (i.e., it is a mirror sequence). The verification must not use extra memory.
Input : [1] → [2] → [3] → [2] → [1] → NULL
Expected Output: TRUE
*/
#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int pin;
Node(int val)
{
    next=NULL;
    pin=val;
}
};
class Bank
{
public:
Node*head;
Node*tail;
Bank()
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
    if(first->pin!=second->pin)
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
    cout<<temp->pin<<" -> ";
    temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
};
int main()
{
 Bank b;
 b.PushFront(1);
 b.PushFront(2);
 b.PushFront(3);
 b.PushFront(2);
 b.PushFront(1);
 b.Display();
 if(b.PalindromeCheck())
 {
    cout<<"True."<<endl;
 }
 else
 {
    cout<<"False"<<endl;
 }
 return 0;
}
     
