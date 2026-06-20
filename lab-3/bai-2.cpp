#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

class SingleLinkedList
{
public:
    Node *head = nullptr;

    void print_list()
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void insert_value(long new_value, long value = NULL)
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

    void delete_node(long value)
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

    long get_value()
    {
        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        return current->value;
    }
};

int main(int argc, char const *argv[])
{
    std::string text = "[{()}]";
    SingleLinkedList linked_list;
    for (auto var : text)
    {
        if (var == '[' || var == '(' || var == '{')
        {
            linked_list.insert_value(var);
        }
        else
        {
            if (linked_list.head == nullptr)
            {
                break;
            }

            char top = linked_list.get_value();

            if (top == '{' && var != '}' || top == '(' && var != ')' || top == '[' && var != ']')
            {
                break;
            }
            linked_list.delete_node(top);
        }
    }

    linked_list.head == nullptr ? std::cout << "Correct" : std::cout << "InCorrect";

    return 0;
}