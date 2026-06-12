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

void merge(std::vector<long> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<long> L(n1);
    std::vector<long> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<long> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    int left = 0;
    int right = arr.size() - 1;

    merge_sort(arr, left, right);

    std::fstream output_file("output-bai-2.txt", std::ios::out);
    for (int i = 0; i < n; i++)
    {
        output_file << arr[i] << " ";
    }

    output_file.close();

    return 0;
}