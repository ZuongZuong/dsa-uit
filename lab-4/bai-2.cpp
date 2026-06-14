#include "SingleLinkedList.h"
#include<iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    std::string text = "[{()}]";
    SingleLinkedList linked_list;

    for(auto var : text)
    {
        if (var == '[' || var == '(' || var == '{')
        {
            linked_list.insert_value(var);
        }
    }

    

    linked_list.print_list();

    return 0;
}
