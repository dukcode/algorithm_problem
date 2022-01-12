#include <vector>
#include <random>
#include <iostream>
#include <algorithm>


void bubbleSort(std::vector<int>& nums)
{
    const int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
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

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    bubbleSort(nums);

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
