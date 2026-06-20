#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "Node.h"

class SingleLinkedList
{
public:
    Node *head = nullptr;

    void print_list();
    void insert_value(char new_value, char value = '\0');
    void delete_node(char value);
};

#endif