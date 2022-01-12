#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

void selection_sort(std::vector<int>& nums);


int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    std::vector<int> nums;
    for (int i = 0; i < 30; ++i)
    {
        nums.emplace_back(dist(mt));
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';

    selection_sort(nums);

    for (const auto& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void selection_sort(std::vector<int>& nums)
{
    const int n = nums.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[minIdx] > nums[j])
            {
                minIdx = j;
            }
        }
        std::swap(nums[i] , nums[minIdx]);
    }
}
