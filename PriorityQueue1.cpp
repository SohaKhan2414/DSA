/*
Sorted array:
*/
#include <iostream>
using namespace std;

class PriorityQueue
{
    int data[100];
    int priority[100];
    int size;

public:

    PriorityQueue()
    {
        size = 0;
    }

    void enqueue(int value, int p)
    {
        if (size == 100)
        {
            cout << "Queue is full";
            return;
        }

        int i = size - 1;

        while (i >= 0 && priority[i] > p)
        {
            data[i + 1] = data[i];
            priority[i + 1] = priority[i];
            i--;
        }

        data[i + 1] = value;
        priority[i + 1] = p;

        size++;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return;
        }

        cout << "Removed: " << data[0] << endl;

        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        size--;
    }

    void peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return;
        }

        cout << data[0] << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << "("
                 << priority[i] << ") ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue q;

    q.enqueue(10, 3);
    q.enqueue(20, 1);
    q.enqueue(30, 5);
    q.enqueue(40, 2);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}