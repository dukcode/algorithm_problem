#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <array>

const int maxRange = 10;

// O(n + rangeSize)
// counting 방법론 - 중복을 해결하기 위한
void countingSort(std::vector<int>& nums)
{
    static std::array<int, maxRange + 1> cache;
    const int n = nums.size();

    for (const int e : nums)
    {
        cache[e]++;
    }


    cache[0]--;
    for (int i = 1; i < maxRange + 1; ++i)
    {
        cache[i] += cache[i - 1];
    }

    std::vector<int> sortedArr(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        sortedArr[cache[nums[i]]--] = nums[i];
    }

    nums = sortedArr;
}

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, maxRange);

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

    countingSort(nums);

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
