#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class Stack{
public:
Node *top;
Stack()
{
    top=NULL;
}
void push(int val)
{
    Node*newnode=new Node(val);
    newnode->next=top;
    top=newnode;
}
void pop()
{
   if(top==NULL)
   {
 cout<<"Underflow."<<endl;
 return;
   }
Node*temp=top;
 top=top->next;
 delete temp;
}
void peek()
{
    if(top==NULL)
    {
        cout<<"Stack empty."<<endl;
        return;
    }
    else
    {
        cout<<"Top: "<<top->data<<endl;
    }
}
bool Empty()
{
    return top==NULL;
}
void display()
{
    Node*temp=top;
    if(top==NULL)
    {
       cout << "Stack is empty." << endl;
            return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
    cout<<endl;
}
};
int main()
{
Stack ss;
ss.push(2);
ss.push(3);
ss.push(10);
ss.peek();
ss.pop();
ss.peek();
ss.display();


}
