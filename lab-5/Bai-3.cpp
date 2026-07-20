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

Node* CreateTree(string s)
{
    stack<Node*> st;

    for (int i = 0;i < s.length();i++)
    {
        if (!IsOperator(s[i]))
        {
            st.push(CreateNode(s[i]));
        }
        else
        {
            Node* r = st.top();
            st.pop();

            Node* l = st.top();
            st.pop();

            Node* p = CreateNode(s[i]);
            p->left = l;
            p->right = r;

            st.push(p);
        }
    }

    return st.top();
}

int Calculate(Node* root)
{
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    int a = Calculate(root->left);
    int b = Calculate(root->right);

    switch (root->data)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }

    return 0;
}

int main()
{
    string postfix = "34+52-*";

    Node* root = CreateTree(postfix);

    cout << "Ket qua = " << Calculate(root);

    return 0;
}