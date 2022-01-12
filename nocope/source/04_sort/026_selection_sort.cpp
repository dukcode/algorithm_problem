#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& nums)
{
    const int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int minIdx = i;
        for (int j = i; j < n; ++j)
        {
            if (nums[j] < nums[minIdx])
            {
                minIdx = j;
            }
        }

        std::swap(nums[i], nums[minIdx]);
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

    selectionSort(nums);

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
