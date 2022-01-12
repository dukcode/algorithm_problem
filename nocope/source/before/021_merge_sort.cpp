#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

void merge_sort(std::vector<int>& nums, int start, int end);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 30);

    std::vector<int> nums;
    for (int i = 0; i < 20; ++i)
    {
        nums.emplace_back(dist(mt));
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';

    merge_sort(nums, 0, nums.size() - 1);

    for (const auto& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void merge_sort(std::vector<int>& nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            temp.emplace_back(nums[i]);
            i++;
        }
        else
        {
            temp.emplace_back(nums[j]);
            j++;
        }
    }

    if (i == mid + 1)
    {
        while (j <= end)
        {
            temp.emplace_back(nums[j]);
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp.emplace_back(nums[i]);
            i++;
        }
    }

    for (int i = start; i <= end; ++i)
    {
        nums[i] = temp[i - start];
    }
}
