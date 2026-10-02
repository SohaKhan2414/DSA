#include<iostream>
using namespace std;
class Node{
public:
Node*next;
Node*prev;
int data;
Node(int val)
{
    next=NULL;
    prev=NULL;
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
    else
    {
        newNode->prev=tail;
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
void RemoveRepeatedNodes()
{
    Node*temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {   Node*nextNode=temp->next;
        if(temp->data==nextNode->data)
        {
            Node*del=nextNode;
            temp->next=del->next;
            if(del->next!=NULL)
            {
             del->next->prev=temp;
            }
            else
            {
                tail=temp;
            }
           
            delete del;
        }
        else
        {
            temp=temp->next;
        }
    }
}
};
int main()
{
 List ll;
 ll.pushBack(1);
 ll.pushBack(1);
 ll.pushBack(2);
 ll.pushBack(2);
 ll.pushBack(2);
 ll.pushBack(3);
 ll.pushBack(3);
 ll.Display();
 ll.RemoveRepeatedNodes();
 ll.Display();
 return 0;
}