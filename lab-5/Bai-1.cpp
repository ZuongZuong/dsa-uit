#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* CreateNode(char x)
{
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* CreateTree(string postfix)
{
    stack<Node*> st;

    for (int i = 0;i < postfix.length();i++)
    {
        char x = postfix[i];

        if (!IsOperator(x))
        {
            st.push(CreateNode(x));
        }
        else
        {
            Node* right = st.top();
            st.pop();

            Node* left = st.top();
            st.pop();

            Node* p = CreateNode(x);
            p->left = left;
            p->right = right;

            st.push(p);
        }
    }

    return st.top();
}