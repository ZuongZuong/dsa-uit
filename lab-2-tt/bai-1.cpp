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

void quick_sort(std::vector<long> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int i = left, j = right;

    srand(std::time(0));
    int pivot_index = (rand() % (right - left + 1)) + left;

    long pivot = arr[pivot_index];

    while (i <= j)
    {
        while (arr[i] > pivot)
        {
            i++;
        }

        while (arr[j] < pivot)
        {
            j--;
        }

        if (i <= j)
        {
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main(int argc, char **args)
{
    generate_data();

    std::fstream input_file("input.txt", std::ios::in);
    int n;
    input_file >> n;

    // long arr[n];

    std::vector<long> arr;

    for (int i = 0; i < n; i++)
    {
        long value;
        input_file >> value;
        arr.push_back(value);
    }

    input_file.close();

    quick_sort(arr, 0, arr.size() - 1);

    std::fstream output_file("output-bai-1.txt", std::ios::out);
    for (int i = 0; i < n; i++)
    {
        output_file << arr[i] << " ";
    }

    output_file.close();

    return 0;
}