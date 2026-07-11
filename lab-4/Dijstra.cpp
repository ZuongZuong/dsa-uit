#include <iostream>
#include <fstream>

using namespace std;

int n;
int a[99][99];

//

void Dijkstra(int start, int finish)
{
    int dist[99];
    int parent[99];
    bool visited[99];

    for (int i = 0; i < n; i++)
    {
        dist[i] = -1;
        parent[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] != -1)
            {
                if (u == -1 || dist[j] < dist[u])
                {
                    u = j;
                }
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (a[u][v] > 0 && !visited[v])
            {
                int newDist = dist[u] + a[u][v];

                if (dist[v] == -1 || newDist < dist[v])
                {
                    dist[v] = newDist;
                    parent[v] = u;
                }
            }
        }
    }

    if (dist[finish] == -1)
    {
        cout << "Khong ton tai duong di!" << endl;
        return;
    }

    cout << "Khoang cach ngan nhat: " << dist[finish] << endl;

    int path[99];
    int cnt = 0;

    int v = finish;
    while (v != -1)
    {
        path[cnt++] = v;
        v = parent[v];
    }

    cout << "Duong di: ";

    for (int i = cnt - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0)
            cout << "->";
    }

    cout << endl;
}

int main()
{
    ifstream fin("input.txt");

    if (!fin)
    {
        cout << "Khong mo duoc file input.txt";
        return 0;
    }

    fin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> a[i][j];

    fin.close();

    int start, finish;

    cout << "Nhap dinh bat dau: ";
    cin >> start;

    cout << "Nhap dinh ket thuc: ";
    cin >> finish;

    Dijkstra(start, finish);

    return 0;
}