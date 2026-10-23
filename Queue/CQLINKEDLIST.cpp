
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void search(int value) {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        do {
            if (temp->data == value) {
                cout << "Value found" << endl;
                return;
            }

            temp = temp->next;

        } while (temp != front);

        cout << "Value not found" << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Searching 20: ";
    q.search(20);

    cout << "Searching 50: ";
    q.search(50);

    cout << "After dequeue: ";
    q.dequeue();
    q.display();

    return 0;
}