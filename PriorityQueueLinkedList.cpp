
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue
{
private:
    Node* front;

public:
    PriorityQueue()
    {
        front = NULL;
    }

    // Insert according to priority
    void enqueue(int data, int priority)
    {
        Node* newNode = new Node(data, priority);

        // Insert at beginning
        if (front == NULL || priority < front->priority)
        {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node* temp = front;

        // Find correct position
        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove highest priority element
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;

        cout << "Removed: " << temp->data << endl;

        front = front->next;

        delete temp;
    }

    // Display queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;

        while (temp != NULL)
        {
            cout << temp->data
                 << "(P" << temp->priority << ") -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    PriorityQueue q;

    q.enqueue(10, 1);
    q.enqueue(20, 3);
    q.enqueue(30, 2);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}
