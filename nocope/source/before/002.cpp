#include <iostream>
#include <random>

const int n = 10000;

void print(int* data, int n);
void swap(int& lhd, int& rhd);
void quick_sort(int* data, int start, int end);


int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(mt);
    }

    print(arr, n);
    quick_sort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}

void print(int* data, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

void swap(int& lhd, int& rhd)
{
    int temp = lhd;
    lhd = rhd;
    rhd = temp;
}

void quick_sort(int* data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;
    int left = start;
    int right = end - 1;

    swap(data[pivot], data[end]);

    while (left <= right)
    {
        while (data[left] <= data[end] && left < end)
        {
            left++;
        }

        while (data[right] >= data[end] && right >= start)
        {
            right--;
        }
        
        if (left < right)
        {
            swap(data[left], data[right]);
        }
    }

    swap(data[left], data[end]);

    quick_sort(data, start, left - 1);
    quick_sort(data, left + 1, end);
}
