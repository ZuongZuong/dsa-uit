#include <iostream>
#include <fstream>

// int n, m;
// int arr[1000][1000];

// std::vector<int> vertus[1000];

// int main(int argc, char const *argv[])
// {
    // std::fstream input_file("input.txt", std::ios::in);

//     input_file >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         input_file >> x >> y;

//         arr[x][y] = 1;
//         arr[y][x] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             std::cout<< arr[i][j] << " ";
//         }
//         std::cout << "\n";
//     }
//     return 0;
// }

int n, m;
std::vector<int> adj[1001];

int main(int argc, char const *argv[])
{
    std::fstream input_file("input.txt", std::ios::in);

    input_file >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        input_file >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << i << ": ";
        for(int val : adj[i])
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
