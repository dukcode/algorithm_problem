// [leetcode 215] Kth Largest Element in an Array
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int quickSelect(std::vector<int>& nums, int start, int end, int targetIdx)
{
    int left = start;
    int right = end - 1;
    int pivot = (start + end) / 2;

    std::swap(nums[pivot], nums[end]);
    while (left <= right)
    {
        while (left < end && nums[left] < nums[end])
        {
            left++;
        }

        while (right >= start && nums[right] >= nums[end])
        {
            right--;
        }

        if (left < right)
        {
            std::swap(nums[left], nums[right]);
        }
    }
    std::swap(nums[left], nums[end]);

    for (auto e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << " left : " << left << '\n';

    if (left == targetIdx)
    {
        return left;
    }
    else if (left < targetIdx)
    {
        return quickSelect(nums, left + 1, end, targetIdx);
    }
    else
    {
        return quickSelect(nums, start, left - 1, targetIdx);
    }

    return -1;
}

int findKthLargest(std::vector<int>& nums, int k)
{
    const int n = nums.size();

    int idx = quickSelect(nums, 0, n - 1, n - k);

    return nums[idx];
    
}

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10);

    std::vector<int> nums;
    for (int i = 0; i < 10; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    std::cout << findKthLargest(nums,2) << '\n';

    return 0;
}
