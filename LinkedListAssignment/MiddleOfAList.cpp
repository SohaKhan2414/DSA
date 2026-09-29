/*
A university examination system stores students' roll numbers as a chain of connected boxes. The invigilator needs to identify the middle student in the queue to distribute answer sheets from the center outward. The system must find the middle box in a single pass without counting the total length first.
Given the head of this chain, return the middle box. If the chain has an even number of boxes, return the second middle box. Solve using the two-pointer technique.
Input (Odd): [1] → [2] → [3] → [4] → [5] → NULL
Expected Output (Odd): Middle  = [3]
Input (Even):[1] → [2] → [3] → [4] → [5] → [6] → NULL
Expected Output (Even): Middle Box = [4]   (second middle)
*/
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
class MiddleOfAList
{
public:
Node*head;
Node*tail;
Node*fast;
Node*slow;
MiddleOfAList()
{
    head=tail=NULL;
}
void pushFront(int val)
{   Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
Node* MiddleofLinkedList()
{   fast=head;
    slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
     slow=slow->next;
     fast=fast->next->next;
    }
    return slow;
}
void Display()
{   Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
}
};
int main()
{
    MiddleOfAList m;
    m.pushFront(1);
    m.pushFront(2);
    m.pushFront(3);
    m.pushFront(4);
    m.pushFront(5);
    m.pushFront(6);
    m.Display();
    Node*middle= m.MiddleofLinkedList();
    cout<<endl;
    cout<<"Middle Box is: ";
    cout<<middle->data;
    return 0;

}