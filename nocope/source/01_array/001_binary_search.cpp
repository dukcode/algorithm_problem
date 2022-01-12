// [leetcode 704] Binary Search
#include <vector>

int search(std::vector<int>& nums, int target)
{
    const int n = nums.size();
    int left = 0;
    int right = n - 1;

    int pivot;
    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (nums[pivot] == target)
        {
            return pivot;
        }
        
        if (nums[pivot] > target)
        {
            right = pivot - 1;
        }
        else
        {
            left = pivot + 1;
        }
    }

    return -1;
}
