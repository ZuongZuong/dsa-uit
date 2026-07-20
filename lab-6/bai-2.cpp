#include <iostream>
using namespace std;


struct Node
{
    int value;
    Node* next;
};

const int tableSize = 10;

Node* hashTable[tableSize];

Node* createNode(int keyValue)
{
    Node* p = new Node();
    p->value = keyValue;
    p->next = NULL;

    return p;
}

void createHashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i] = NULL;
    }
}

int hashFunction(int keyValue)
{
    return keyValue % tableSize;
}

void insert(Node* &curNode, int keyValue)
{
    if (curNode == NULL)
    {
        curNode = createNode(keyValue);
        return;
    }
    else insert(curNode->next, keyValue);

    return;
}

void search(Node*& curNode, int keyValue)
{
    if (curNode == NULL)
    {
        cout << "key nay khong ton tai. " << endl;
        return;
    }
    
    if (curNode->value == keyValue)
    {
        cout << "tim thay key. " << keyValue << endl;
        return;
    }
    else search(curNode->next, keyValue);

}

void deleteKey(Node*& preNode, Node*& curNode, int keyValue)
{
    if (curNode == NULL)
    {
        cout << "key nay khong ton tai. " << endl;
        return;
    }
    
    if (curNode->value == keyValue)
    {
        preNode->next = curNode->next;
        curNode = NULL;
        cout << "da xoa key nay. " << endl;
        return;
    }
    else (curNode, curNode->next, keyValue);

}

void display1(Node* node)
{
    if (node == NULL) return;
    
    cout << node->value << " ";
    display1(node->next);
    return;
}

void display()
{
    cout << "\nHash Table\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << " : ";
        display1(hashTable[i]);
        cout << endl;
    }

    return;
}

int main()
{
    createHashTable();

    int n; cin >> n; // so luong key

    for (int i = 0;i < n;i++)
    {
        int key;
        cout << "nhap: ";
        cin >> key;
        insert(hashTable[hashFunction(key)], key);
    }

    cout << "\nsau khi nhap:\n";
    display();

    
    cout << "\ntim kiem: ";
    int skey; cin >> skey;
    search(hashTable[hashFunction(skey)], skey);

    
    cout << "\nxoa: ";
    int dkey; cin >> dkey;
    deleteKey(hashTable[hashFunction(skey)],hashTable[hashFunction(skey)], dkey);

    
    cout << "\nsau khi xoa:\n";
    display();

    cout << endl;

    return 0;
}