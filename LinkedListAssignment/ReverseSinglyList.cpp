/*
A music streaming app stores a user's "Recently Played" songs as a chain of connected boxes, where each box holds a song and a pointer to the next box. The most recently played song sits at the front. A software update accidentally reversed the display order. The team must now reverse the entire chain in-place so the oldest played song appears first  without creating any new boxes.
Given the head of this chain, reverse it in-place and return the new head. You must not allocate new memory. Show the pointer manipulation at each step.
Input:  [10] → [20] → [30] → [40] → [50] → NULL
Expected Output: [50] → [40] → [30] → [20] → [10] → NULL
*/
#include<iostream>
using namespace std;
class Node{
public:
Node* next;
string song;
Node(string s)
{ 
    song=s;
    next=NULL;
}
};
class Songs{
public:
Node*head;
Node*tail;
Songs()
{
  head=tail=NULL;
}
void pushFront(string s)
{
  Node*newNode=new Node(s);
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
void Reversal()
{
  Node*oldhead=head;
  Node*current=head;
  Node*next=NULL;
  Node*prev=NULL;
  while(current!=NULL)
  {
  next=current->next;
  current->next=prev;
  prev=current;
  current=next;
  }
  head=prev;
  tail=oldhead;
}
void Display()
{
    Node*current=head;
    while(current!=NULL)
    {
        cout<<current->song<<" ";
        current=current->next;

    }
    cout<<endl;
}
};
int main()
{
    Songs s;
    s.pushFront("OneThing");
    s.pushFront("NightChanges");
    s.pushFront("StealMyGirl");
    cout<<"Before Reversal: "<<endl;
    s.Display();
    s.Reversal();
    cout<<"After Reversal: "<<endl;
    s.Display();
    return 0;
}
