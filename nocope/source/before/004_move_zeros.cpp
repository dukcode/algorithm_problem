#include <iostream>
#include <random>

const int n = 30;

void print(int* data, int n);
void swap(int& lhd, int& rhd);
void quick_sort(int* data, int start, int end);
int binary_search(int* data, int n, int target);
void move_zeros(int* data, int n);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(mt);
    }

    print(arr, n);
    move_zeros(arr, n);
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

int binary_search(int* data, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int pivot = (left + right) / 2;

        if (data[pivot] == target)
        {
            return pivot;
        }

        if (data[pivot] < target)
        {
            left = pivot + 1;
        }

        if (data[pivot] > target)
        {
            right = pivot - 1;
        }
    }

    return -1;
}

void move_zeros(int* data, int n)
{
    int readingIdx = 0;

    for (int writingIdx = 0; writingIdx < n; writingIdx++)
    {
        if (data[writingIdx] != 0)
        {
            data[readingIdx] = data[writingIdx];
            readingIdx++;
        }
    }

    while (readingIdx < n)
    {
        data[readingIdx] = 0;
        readingIdx++;
    }

}
