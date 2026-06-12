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
};

int main()
{
    SingleLinkedList linked_list;

    linked_list.insert_value(10);
    linked_list.insert_value(15);
    linked_list.insert_value(20);
    linked_list.insert_value(16, 15);

    linked_list.print_list();

    linked_list.delete_node(10);

    linked_list.print_list();

    return 0;
}