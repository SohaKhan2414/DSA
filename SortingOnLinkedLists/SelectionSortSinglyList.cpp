#include<iostream>
using namespace std;
class Node{
public:
Node*next;
int data;
public:
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
Node*newNode=new Node (val);
if(head==NULL)
{
    head=tail=newNode;
}
tail->next=newNode;
tail=newNode;
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
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    Node*temp=head;
    while(temp!=NULL)
    {
        Node*min=temp;
        Node*current=temp->next;
        while(current!=NULL)
        {
            if(current->data<min->data)
            {
                min=current;
            }
            current=current->next;
        }

        if(min!=temp)
        {
        int x=temp->data;
        temp->data=min->data;
        min->data=x;
        }
        temp=temp->next;
    }

}
};
int main()
{
List ll;
ll.pushBack(5);
ll.pushBack(1);
ll.pushBack(3);
ll.pushBack(2);
ll.pushBack(4);
ll.Display();
ll.Sort();
ll.Display();

}