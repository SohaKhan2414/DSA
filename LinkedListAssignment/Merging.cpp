/*
Two departments of a company each maintain their employee IDs in a sorted list. The HR department wants to merge both lists into a single sorted list for payroll processing. The merge must be done by rearranging the existing list.
Given the heads of two sorted list, merge them into one sorted list and return its head.
Input:
Chain A: HEAD1 → [1] → [3] → [5] → [7] → NULL
Chain B: HEAD2 → [2] → [4] → [6] → [8] → NULL
Expected Output:  [1] → [2] → [3] → [4] → [5] → [6] → [7] → [8] → NULL
*/
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
class List{
public:
Node*head1;
Node*head2;
List()
{
    head1=NULL;
    head2=NULL;
}
void Pushfront1(int val)
{  
    Node*newNode=new Node(val);
    if(head1==NULL)
    {
     head1=newNode;
     return;
    }
    newNode->next=head1;
    head1=newNode;
}
void Pushfront2(int val)
{
    Node*newNode=new Node(val);
    if(head2==NULL)
    {
     head2=newNode;
     return;
    }
    newNode->next=head2;
    head2=newNode;
}
Node* Merge(Node*head1,Node*head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    
    if(head2==NULL)
    {
        return head1;
    }
    Node*head=NULL;
    Node*tail=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        Node*temp;
        if(head1->data<head2->data)
        {
            temp=head1;
            head1=head1->next;
        }
        else
        {
            temp=head2;
            head2=head2->next;
        }
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    
    }
    if(head1!=NULL)
    {
        tail->next=head1;
    }
    if(head2!=NULL)
    {
        tail->next=head2;
    }
    return head;
}
void Display(Node*head)
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
ll.Pushfront1(7);
ll.Pushfront1(5);
ll.Pushfront1(3);
ll.Pushfront1(1);
ll.Display(ll.head1);
ll.Pushfront2(8);
ll.Pushfront2(6);
ll.Pushfront2(4);
ll.Pushfront2(2);
ll.Display(ll.head2);
Node* merge=ll.Merge(ll.head1,ll.head2);
cout<<"Merged List: ";
ll.Display(merge);
return 0;
}