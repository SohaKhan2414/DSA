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
Node*first;
Node*second;
Node*third;
List()
{
    head=tail=NULL;
    first=NULL;
    second=NULL;
    third=NULL;
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

}
void TripletsCheck(int x)
{
    Node*first=head;
    int count=0;

    while(first!=NULL)
    {   
        Node*second=first->next;
        while(second!=NULL)
        {
            Node*third=second->next;
            while(third!=NULL)
            {
                int sum=first->data+second->data+third->data;
                if(sum==x)
                {
                    count++;
                }
                third=third->next;
            }
            second=second->next;
        }
        first=first->next;
    }
    cout<<"Matching: "<<count<<endl; 
}
};
int main()
{
List ll;
ll.pushBack(1);
ll.pushBack(2);
ll.pushBack(3);
ll.pushBack(6);
ll.pushBack(4);
ll.pushBack(0);
ll.pushBack(5);
ll.Display();
ll.TripletsCheck(6);
return 0;
}