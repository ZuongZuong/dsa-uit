#include <iostream>
using namespace std;

const int tableSize = 10;

int hashTable[tableSize];

void create()
{
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i] = -1;
    }
}

int hashFunction(int keyValue)
{
    return keyValue % tableSize;
}

void insert(int keyValue)
{
    int hashIndex = hashFunction(keyValue);

    hashTable[hashIndex] = keyValue;
}

void search(int keyValue)
{
    int hashIndex = hashFunction(keyValue);

    if (hashTable[hashIndex] == keyValue)
    {
        cout << "tim thay key. " << keyValue << endl;
    }
    else
    {
        cout << "khong tim thay key. " << endl;
    }
}

void deleteKey(int keyValue)
{
    int hashIndex = hashFunction(keyValue);

    if (hashTable[hashIndex] == keyValue)
    {
        hashTable[hashIndex] = -1;
        cout << "da xoa key nay. " << endl;
    }
    else
    {
        cout << "key nay khong ton tai. " << endl;
    }
}

void display()
{
    cout << "\nHash Table\n";

    for (int i = 0; i < tableSize; i++)
    {
        cout << i << " : " << hashTable[i] << endl;
    }
}

int main()
{
    create();

    int n; cin >> n;
    int a[99]; 

    for (int i = 0;i < n;i++)
    {
        cout << "nhap: ";
        cin >> a[i];
        insert(a[i]);
    }

    cout << "\nsau khi nhap:\n";
    display();

    
    cout << "\ntim kiem: ";
    int m; cin >> m;
    search(m);

    
    cout << "\nxoa: ";
    int l; cin >> l;
    deleteKey(l);

    
    cout << "\nsau khi xoa:\n";
    display();

    cout << endl;

    return 0;
}