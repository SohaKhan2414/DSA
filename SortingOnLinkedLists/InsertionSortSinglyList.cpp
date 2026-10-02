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
    head=tail=NULL;
}
void pushBack(int val)
{
    Node*newNode=new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else{
        
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
void Sort()
{
if(head==NULL&&head->next==NULL)
{
    return;
}
Node*current=head->next;
while(current!=NULL)
{
int key=current->data;
Node*temp=head;
while(temp!=current)
{
if(temp->data>key)
{
    int x=temp->data;
    temp->data=key;
    key=x;
}
temp=temp->next;
}
current->data=key;
current=current->next;
}
}
};

int main()
{
List ll;
ll.pushBack(5);
ll.pushBack(4);
ll.pushBack(2);
ll.pushBack(1);
ll.Display();
ll.Sort();
ll.Display();
return 0;
}