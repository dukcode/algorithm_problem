#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

void quickSort(std::vector<int>& nums, int start, int end)
{
    int left = start;
    int right = end - 1;

    if (left >= right)
    {
        return;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(start, end);

    int pivot = dist(mt);

    std::swap(nums[pivot] , nums[end]);
    while (left <= right)
    {
        while (left < end && nums[left] < nums[end])
        {
            left++;
        }

        while (right >= start && nums[end] <= nums[right])
        {
            right--;
        }

        if (left < right)
        {
            std::swap(nums[left], nums[right]);
        }
    }

    std::swap(nums[left], nums[end]);

    quickSort(nums, start, left - 1);
    quickSort(nums, left + 1, end);
}

void sortArray(std::vector<int>& nums)
{
    const int n = nums.size();
    quickSort(nums, 0, n - 1);
}

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 99);

    std::vector<int> nums;
    for (int i = 0; i < 20; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    sortArray(nums);

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
