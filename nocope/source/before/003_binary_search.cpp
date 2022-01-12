#include <iostream>

int binary_search_recursive(int* nums, int target, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int pivot = (left + right) / 2;

    if (nums[pivot] == target)
    {
        return pivot;
    }
    else if (nums[pivot] < target)
    {
        left = pivot + 1;
    }
    else if (nums[pivot] > target)
    {
        right = pivot - 1;
    }

    return binary_search_recursive(nums, target, left, right);
}

int binary_search(int* nums, int target, int left, int right)
{
    while (left <= right)
    {
        int pivot = (left + right) / 2;

        if (nums[pivot] == target)
        {
            return pivot;
        }
        else if (nums[pivot] < target)
        {
            left = pivot + 1;
        }
        else if (nums[pivot] > target)
        {
            right = pivot - 1;
        }
    }

    return -1;
}

int main(void)
{
    const int n = 10;
    int nums[n] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10};

    std::cout << binary_search(nums, 8, 0, n - 1) << '\n';

    return 0;
}
