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
void Sort(int size)
{
 for(int gap=size/2;gap>=1;gap=gap/2)
 {
    for(int j=gap;j<size;j++)
    {
        Node*current=head;
        for(int k=0;k<j;k++)
        {
            current=current->next;
        }
        Node*tempNode=current;
        for(int i=j-gap;i>=0;i=i-gap)
        {
            Node*prev=head;
            for(int k=0;k<i;k++)
            {
                prev=prev->next;
            }
            if(tempNode->data>prev->data)
            {
                break;
            }
            else
            {
                int temp=prev->data;
                prev->data=tempNode->data;
                tempNode->data=temp;

                tempNode=prev;
            }
        }
    }
 }

}
};
int main()
{
    List ll;
    ll.pushBack(5);
    ll.pushBack(3);
    ll.pushBack(1);
    ll.pushBack(2);
    ll.Display();
    ll.Sort(4);
    ll.Display();
    return 0;
}