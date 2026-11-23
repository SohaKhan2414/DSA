/*
Maxheap
*/

#include <iostream>
using namespace std;

class PriorityQueue
{
    int heap[100];
    int size;

public:

    PriorityQueue()
    {
        size = 0;
    }

    void enqueue(int value)
    {
        if (size == 100)
            return;

        heap[size] = value;

        int i = size;
        size++;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (heap[i] > heap[parent])
            {
                int temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;

                i = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int i)
    {
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != i)
            {
                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;

                i = largest;
            }
            else
                break;
        }
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty";
            return;
        }

        cout << "Removed: " << heap[0] << endl;

        heap[0] = heap[size - 1];

        size--;

        heapifyDown(0);
    }

    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty";
            return;
        }

        cout << "Highest Priority: " << heap[0] << endl;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty";
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue q;

    q.enqueue(40);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(50);

    cout << "Max Heap: ";
    q.display();

    q.peek();

    q.dequeue();

    cout << "After Deletion: ";
    q.display();

    return 0;
}