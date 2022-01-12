#include <iostream>
#include <array>
#include <random>

const int n = 10;

void swap(int& lhs, int& rhs);
void quick_sort(std::array<int, n>& arr, int left, int right);

int main(void)
{
    std::array<int, n> arr;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    for (auto& e : arr)
    {
        e = dist(mt);
    }

    for (const auto& e : arr)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    quick_sort(arr, 0, n - 1);

    for (const auto& e : arr)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void quick_sort(std::array<int, n>& arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;
    int left = start;
    int right = end - 1;

    swap(arr[pivot], arr[end]);

    while (left <= right)
    {
        while (arr[left] <= arr[end] && left < end)
        {
            left++;
        }

        while (arr[right] >= arr[end] && right >= 0)
        {
            right--;
        }

        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[left], arr[end]);

    quick_sort(arr, start, left - 1);
    quick_sort(arr, left + 1, end);
}
