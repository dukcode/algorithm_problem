#include <iostream>
#include <array>

int binary_search(const array<int, n>& arr, int left, int right, int target);
{
    int pivot;
    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (arr[pivot] == target)
        {
            return pivot;
        }

        if (arr[pivot] < target)
        {
            left = pivot + 1;
        }

        if (arr[pivot] > target)
        {
            right = pivot - 1;
        }
    }

    return -1;
}

int main(void)
{

    return 0;
}
