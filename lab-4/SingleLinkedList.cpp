#include <iostream>
#include "SingleLinkedList.h"

void SingleLinkedList::print_list()
{
    Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void SingleLinkedList::insert_value(char new_value, char value)
{
    if (head == nullptr)
    {
        head = new Node(new_value);
        return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        if (current->value == value)
        {
            Node *new_node = new Node(new_value);

            new_node->next = current->next;
            current->next = new_node;

            return;
        }

        current = current->next;
    }

    current->next = new Node(new_value);
}

void SingleLinkedList::delete_node(char value)
{
    if (head == nullptr)
        return;

    if (head->value == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        if (current->next->value == value)
        {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }

        current = current->next;
    }
}