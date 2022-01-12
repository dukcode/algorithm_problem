#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

void insertion_sort(std::vector<int>& nums);


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

    insertion_sort(nums);

    for (const auto& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void insertion_sort(std::vector<int>& nums)
{
    const int n = nums.size();

    for (int pIdx = 1; pIdx < n; ++pIdx)
    {
        int num = nums[pIdx];
        int idx = pIdx - 1;

        while (idx >= 0 && nums[idx] > num)
        {
            nums[idx + 1] = nums[idx];
            idx--;
        }
        nums[idx + 1] = num;
    }
}
