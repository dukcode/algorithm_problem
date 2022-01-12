// [leetcode 162] Find Peak Element
#include <vector>

int findPeakElement(vector<int>& nums)
{
    const int n = nums.size();
    if (n == 1)
    {
        return 0;
    }

    int left = 0;
    int right = n - 1;

    int pivot;

    while (left < right)        // pivot을 평균으로 잡을 때는 array length = 1 제외하고 pivot + 1 항상 존재함을 고려하여 코드 짜기
    {
        pivot = (left + right) / 2;

        if (nums[pivot] < nums[pivot + 1])
        {
            left = pivot + 1;
        }
        else
        {
            right = pivot;
        }
    }

    return left;
}
