#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

void bubble_sort(std::vector<int>& nums);


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

    bubble_sort(nums);

    for (const auto& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void bubble_sort(std::vector<int>& nums)
{
    const int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}
