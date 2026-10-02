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
}
void Sort()
{
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    Node*end=NULL;
    bool swapped=false;
    do
    {
    swapped=false;
    Node*temp=head;
    while(temp->next!=end)
    {
        if(temp->data>temp->next->data)
        {
            int x=temp->data;
            temp->data=temp->next->data;
            temp->next->data=x;
            swapped=true;
        }
        temp=temp->next;
    }
    end=temp;

    } while (swapped);    
}
};
int main()
{
    List ll;
    ll.pushBack(3);
    ll.pushBack(1);
    ll.pushBack(4);
    ll.pushBack(2);
    ll.Display();
    cout<<endl;
    ll.Sort();
    ll.Display();
    return 0;
}
