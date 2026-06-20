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

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

};

int main(int argc, char const *argv[])
{
    std::fstream input_file("input.txt", std::ios::in);
    int n, r;
    input_file >> n >> r;

    Queue q;


    return 0;
}