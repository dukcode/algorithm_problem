// [leetcode 88] Merge Sorted Array
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int num1Idx = m - 1;
    int num2Idx = n - 1;

    int widingIdx = nums1.size() - 1;
    while (widingIdx >= 0 && num1Idx >=0 && nums2Idx >= 0)
    {
        if (nums1[num1Idx] > nums2[num2Idx])
        {
            nums1[widingIdx] = nums1[num1Idx];
            num1Idx--;
            widingIdx--;
        }
        else
        {
            nums1[widingIdx] = nums2[num2Idx];
            num2Idx--;
            widingIdx--;
        }
    }

    while (num2Idx >= 0)
    {
        nums1[widingIdx] = nums2[num2Idx];
        num2Idx--;
        widingIdx--;
    }
}
