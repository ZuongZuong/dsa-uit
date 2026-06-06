#include <iostream>
#include <fstream>
#include <vector>

void swap(long &a, long &b)
{
    long temp = a;
    a = b;
    b = temp;
}

void bubble_sort(long arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void bubble_sort_vector(std::vector<long>& arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr.size() - 1; j > i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

int main(int argc, char **args)
{

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

    // bubble_sort(arr, n);
    bubble_sort_vector(arr);

    std::fstream output_file("output-1.txt", std::ios::out);
    for (int i = 0; i < n; i++)
    {
        output_file << arr[i] << " ";
    }

    output_file.close();
    return 0;
}