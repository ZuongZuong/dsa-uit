#include <iostream>

class Node
{
public:
    long value;
    Node *next;
    Node *prev;

    Node(long value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void print_forward()
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    void print_backward()
    {
        Node *current = tail;

        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->prev;
        }

        std::cout << std::endl;
    }

    void insert_value(long new_value, long value = -1)
    {
        Node *new_node = new Node(new_value);

        if (head == nullptr)
        {
            head = tail = new_node;
            return;
        }

        if (value == -1)
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            return;
        }

        Node *current = head;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                new_node->next = current->next;
                new_node->prev = current;

                if (current->next != nullptr)
                {
                    current->next->prev = new_node;
                }
                else
                {
                    tail = new_node;
                }

                current->next = new_node;
                return;
            }

            current = current->next;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void delete_node(long value)
    {
        if (head == nullptr)
            return;

        Node *current = head;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                if (current == head)
                {
                    head = head->next;

                    if (head != nullptr)
                        head->prev = nullptr;
                    else
                        tail = nullptr;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }

            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.insert_value(10);
    list.insert_value(15);
    list.insert_value(20);
    list.insert_value(16, 15);

    std::cout << "Forward: ";
    list.print_forward();

    std::cout << "Backward: ";
    list.print_backward();

    list.delete_node(10);

    std::cout << "After delete 10:" << std::endl;

    std::cout << "Forward: ";
    list.print_forward();

    std::cout << "Backward: ";
    list.print_backward();

    return 0;
}