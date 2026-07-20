#include <iostream>
using namespace std;


struct Node
{
    int value;
    int next;
};

const int tableSize = 10;

Node hashTable[tableSize];

Node createNode(int keyValue)
{
    Node p;
    p.value = keyValue;
    p.next = -1;

    return p;
}

void createHashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i].value = -1;
    }
}

int hashFunction(int keyValue)
{
    return keyValue % tableSize;
}

int findEmpty()
{
    int index = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].value == -1) 
        {
            index = i; return index;
        }
    }

    return -1;
}

void insert(int keyValue)
{
    int index = hashFunction(keyValue);
    
    if (hashTable[index].value == -1)
    {
        hashTable[index].value = keyValue;
        return;
    }
    else if (findEmpty() == -1) cout << "da het o trong. ";
        else hashTable[findEmpty()].value = keyValue;

    return;
}

void search(int keyValue)
{
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].value == keyValue)
        {
            cout << "tim thay key o vi tri " << i;
            return;
        }
    }

	cout << "key nay khong ton tai. " << endl;
	return;

}

void del(int keyValue)
{
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].value == keyValue)
        {
            for (int j = 0; j < tableSize; j++)
            {
                if (hashTable[j].next == i)
                {
                    hashTable[j].next = hashTable[i].next;
                    break;
                }
            }

            hashTable[i].value = -1;
            hashTable[i].next = -1;
            cout << "da xoa key. " << i;
            return;
        }
    }
    
    cout << "key khong ton tai. " << endl;
    return;

}

void display()
{
    for (int i = 0; i < tableSize; i++)
        cout << i << " : value: " << hashTable[i].value << " , next position: " << hashTable[i].next << endl;
    
    return;
}


int main()
{
    createHashTable();

    int n; cin >> n; // so luong key

    cout << "nhap: ";
    for (int i = 0;i < n;i++)
    {
        int key;
        cin >> key;
        insert(key);
    }

    cout << "\nsau khi nhap:\n";
    display();

    
    cout << "\ntim kiem: ";
    int skey; cin >> skey;
    search(skey);

    
    cout << "\nxoa: ";
    int dkey; cin >> dkey;
    del(dkey);

    
    cout << "\nsau khi xoa:\n";
    display();

    cout << endl;

    return 0;
}