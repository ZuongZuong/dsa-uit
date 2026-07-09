#include <iostream>
#include <fstream>

class Node
{
public:
    long value;
    Node *next;

    Node(long value, Node *next = nullptr)
        : value(value), next(next)
    {
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack() : head(nullptr)
    {
    }

    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(long value)
    {
        head = new Node(value, head);
    }

    long pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty.");
        }

        Node *temp = head;
        long value = temp->value;

        head = head->next;
        delete temp;

        return value;
    }

    long peek() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty.");
        }

        return head->value;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

char digit(long value)
{
    if (value < 10)
        return '0' + value;

    return 'A' + (value - 10);
}

int main()
{
    std::ifstream input_file("input.txt");

    if (!input_file)
    {
        std::cout << "Cannot open input.txt" << std::endl;
        return 1;
    }

    long n;
    int r;

    input_file >> n >> r;

    if (r < 2 || r > 36)
    {
        std::cout << "Base must be between 2 and 36." << std::endl;
        return 1;
    }

    Stack s;

    if (n == 0)
    {
        s.push(0);
    }
    else
    {
        while (n > 0)
        {
            s.push(n % r);
            n /= r;
        }
    }

    std::cout << "Result: ";

    while (!s.isEmpty())
    {
        std::cout << digit(s.pop());
    }

    std::cout << std::endl;

    input_file.close();

    return 0;
}