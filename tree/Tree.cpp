#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* Insert(Node* root, int x)
{
    if (root == NULL)
        return CreateNode(x);

    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);

    return root;
}

void PreOrder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " -> ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " -> ";
}

void InOrder(Node* root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " -> ";
    InOrder(root->right);
}

int main()
{
    ifstream fin("input.txt");

    if (!fin)
    {
        cout << "Khong mo duoc file!";
        return 0;
    }

    int n;
    fin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;
        root = Insert(root, x);
    }

    fin.close();

    cout << "1. Duyet theo thu tu truoc:" << endl;
    PreOrder(root);

    cout << endl << endl;

    cout << "2. Duyet theo thu tu sau:" << endl;
    PostOrder(root);

    cout << endl << endl;

    cout << "3. Day so sau khi sap xep:" << endl;
    InOrder(root);

    cout << endl;

    return 0;
}