#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue()
    {
        front = rear = nullptr;
        count = 0;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int size()
    {
        return count;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }

        Node *temp = front;
        int value = front->data;

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        count--;

        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        return front->data;
    }
};

int main()
{
    int n, k;

    std::cout << "Enter number of people (n): ";
    std::cin >> n;

    std::cout << "Enter step (k): ";
    std::cin >> k;

    Queue q;

    for (int i = 1; i <= n; i++)
    {
        q.enqueue(i);
    }

    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            int person = q.dequeue();
            q.enqueue(person);
        }

        int eliminated = q.dequeue();
        std::cout << "Eliminated: " << eliminated << std::endl;
    }

    std::cout << "\nSurvivor: " << q.peek() << std::endl;

    return 0;
}