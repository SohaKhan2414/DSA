/*
Min heap
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

            if (heap[i] < heap[parent])
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
            int smallest = i;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i)
            {
                int temp = heap[i];
                heap[i] = heap[smallest];
                heap[smallest] = temp;

                i = smallest;
            }
            else
                break;
        }
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Empty";
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
            cout << "Empty";
        else
            cout << "Highest Priority: " << heap[0] << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

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

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}
