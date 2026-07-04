#include <iostream>
#include <fstream>

int arr[1001][1001];
int trace[1001];
bool visit[1001];

void DFS(int u, int V)
{
    visit[u] = true;
    for (int v = 1; v <= V; v++)
    {
        if (!visit[v] && arr[u][v] == 1)
        {
            trace[v] = u;
            DFS(v, V);
        }
    }
}

int main(int argc, char const *argv[])
{
    int V = 0, E = 0, s = 0, f = 0;

    std::fstream input_file("input.txt", std::ios_base::in);
    input_file >> V >> E >> s >> f;

    for (int u = 1; u <= V; u++)
    {
        for (int v = 1; v <= V; v++)
        {
            arr[u][v] = 0;
        }
    }

    for (int e = 1; e <= E; e++)
    {
        int u = 0, v = 0;
        input_file >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1; 
    }

    input_file.close();

    for (int v = 1; v <= V; v++)
    {
        visit[v] = false;
        trace[v] = 0;
    }

    DFS(s, V);

    if (visit[f])
    {
        int p = f;
        while (p != s)
        {
            std::cout << p << " <-- ";
            p = trace[p];
        }
        std::cout << s << std::endl;
    }
    return 0;
}