#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdio>

void quick_sort(std::vector<int>& nums, int startIdx, int endIdx);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1000);

    std::vector<int> nums;
    for (int i; i < 1000; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << "\n\n";

    quick_sort(nums, 0, nums.size() - 1);
    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void quick_sort(std::vector<int>& nums, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
    {
        return;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(startIdx, endIdx);

    int pivotIdx = dist(mt);
    std::swap(nums[pivotIdx], nums[endIdx]);

    int leftIdx = startIdx;
    int rightIdx = endIdx - 1;

    while (leftIdx <= rightIdx)
    {
        while (nums[leftIdx] <= nums[endIdx] && leftIdx < endIdx)
        {
            leftIdx++;
        }

        while (nums[rightIdx] > nums[endIdx] && rightIdx >= startIdx)
        {
            rightIdx--;
        }

        if (leftIdx < rightIdx)
        {
            std::swap(nums[leftIdx] , nums[rightIdx]);
        }
    }
    std::swap(nums[leftIdx], nums[endIdx]);

    quick_sort(nums, startIdx, leftIdx - 1);
    quick_sort(nums, leftIdx + 1, endIdx);
}
