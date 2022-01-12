// [leetcode 581] Shortest Unsorted Continuous Subarray
#include <vector>
#include <limits>

int findUnsortedSubarray(std::vector<int>& nums)
{
    const int n = nums.size();

    int start = -1;
    int end = -2;

    int maxValue = std::numeric_limits<int>::min();
    int minValue = std::numeric_limits<int>::max();

    for (int i = 0; i < n; ++i)
    {
        maxValue = max(maxValue, nums[i]);
        if (maxValue > nums[i])
        {
            end = i;
        }

        minValue = min(minValue, nums[n - 1 - i]);
        if (minValue < nums[n - 1 - i])
        {
            start = n - 1 - i;
        }
    }

    return end - start + 1;
}
