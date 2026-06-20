#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

class Node
{
public:
    long value;
    Node *next;

    Node(long value, Node *next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(long value)
    {
        head = new Node(value, head);
    }

    long pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }

        Node *temp = head;
        long value = head->value;

        head = head->next;
        delete temp;

        return value;
    }

    long peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }

        return head->value;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print()
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

int main(int argc, char const *argv[])
{
    std::fstream input_file("input.txt", std::ios::in);
    int n, r;
    input_file >> n >> r;

    Stack s;

    while (n > 0)
    {
        s.push(n % r);
        n /= r;
    }

    s.print();

    return 0;
}