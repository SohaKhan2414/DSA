/*
Unsorted array:
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

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int value, int p)
    {
        if (size == 100)
        {
            cout << "Queue is full";
            return;
        }

        data[size] = value;
        priority[size] = p;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return;
        }

        int minIndex = 0;

        for (int i = 1; i < size; i++)
        {
            if (priority[i] < priority[minIndex])
            {
                minIndex = i;
            }
        }

        cout << "Removed: " << data[minIndex] << endl;

        for (int i = minIndex; i < size - 1; i++)
        {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        size--;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return;
        }

        int minIndex = 0;

        for (int i = 1; i < size; i++)
        {
            if (priority[i] < priority[minIndex])
            {
                minIndex = i;
            }
        }

        cout << data[minIndex] << endl;
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

    q.peek();

    return 0;
}
