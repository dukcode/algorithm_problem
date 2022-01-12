#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int quick_select(std::vector<int>& nums, int start, int end, int targetIdx);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    std::vector<int> nums;
    for (int i; i < 30; ++i)
    {
        nums.emplace_back(dist(mt));
    }
    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    int target = 5;
    std::cout << target << "th index : " << quick_select(nums, 0, nums.size() - 1, target) << '\n';

    std::sort(nums.begin(), nums.end());
    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

int quick_select(std::vector<int>& nums, int start, int end, int targetIdx)
{
    if (start >= end)
    {
        return nums[end];
    }

    int pivotIdx = (start + end) / 2;
    std::swap(nums[pivotIdx], nums[end]);

    int left = start;
    int right = end - 1;

    while (left <= right)
    {
        while (nums[left] <= nums[end] && left < end)
        {
            left++;
        }

        while (nums[right] > nums[end] && right >= start)
        {
            right--;
        }

        if (left < right)
        {
            std::swap(nums[left], nums[right]);
        }
    }

    std::swap(nums[left], nums[end]);
    if (left == targetIdx)
    {
        return nums[left];
    }
    else if (left < targetIdx)
    {
        return quick_select(nums, left + 1, end, targetIdx);
    }
    else
    {
        return quick_select(nums, start, left - 1, targetIdx);
    }
    
}
