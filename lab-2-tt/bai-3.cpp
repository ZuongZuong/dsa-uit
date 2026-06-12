#include <iostream>
#include <fstream>
#include <vector>

// R value and L value

void generate_data()
{
    std::fstream output_file("input.txt", std::ios::out);

    int n;

    srand(time(NULL));
    n = rand() % 100 + 1;

    output_file << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        output_file << rand() % 1000 + 1 << " ";
    }

    output_file.close();

    std::cout << "Generated n = " << n << std::endl;
}

void swap(long &a, long &b)
{
    long temp = a;
    a = b;
    b = temp;
}

void adujust(std::vector<long> &arr, long root, long end_node)
{

    int c_root; // declare a child root

    long key = arr[root]; // get value from root arr[0]

    while (root * 2 <= end_node) // if root > end_node => break
    {
        c_root = root * 2;                                      // find index of child root
        if (c_root < end_node && arr[c_root] < arr[c_root + 1]) // select node have a largest value
            c_root++;

        if (arr[c_root] <= key) // if new root is not bigger than current root -> break
            break;

        // if new root is bigger than root current root -> swap value and index
        arr[root] = arr[c_root];
        root = c_root;
    }
    arr[root] = key;
}

void heap_sort(std::vector<long> &arr)
{
    int N = arr.size() - 1;

    for (int R = N / 2; R >= 1; R--)
    {
        adujust(arr, R, N);
    }

    for (int i = N; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        adujust(arr, 0, i - 1);
    }
}

int main(int argc, char **args)
{
    generate_data();

    std::fstream input_file("input.txt", std::ios::in);
    int n;
    input_file >> n;

    std::vector<long> arr;

    for (int i = 0; i < n; i++)
    {
        long value;
        input_file >> value;
        arr.push_back(value);
    }

    input_file.close();

    heap_sort(arr);

    std::fstream output_file("output-bai-3.txt", std::ios::out);
    for (int i = 0; i < n; i++)
    {
        output_file << arr[i] << " ";
    }

    output_file.close();

    return 0;
}