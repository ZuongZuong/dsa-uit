#include <iostream>
#include <fstream>
#include <vector>

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

void selection_sort(std::vector<long> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
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

    selection_sort(arr);

    std::fstream output_file("output-2.txt", std::ios::out);
    for (int i = 0; i < n; i++)
    {
        output_file << arr[i] << " ";
    }

    output_file.close();
    return 0;
}