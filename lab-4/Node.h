#ifndef NODE_H
#define NODE_H

class Node
{
public:
    long value;
    Node *next;

    Node(long value, Node *next = nullptr);
};

#endif