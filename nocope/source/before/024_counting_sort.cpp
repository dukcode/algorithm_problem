#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdio>

void counting_sort(std::vector<int>& nums, int minNum, int maxNum);

int main(void)
{
    int minNum = 0;
    int maxNum = 10;

    std::random_device rd; std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minNum, maxNum);

    std::vector<int> nums;
    for (int i; i < 50; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << "\n\n";

    counting_sort(nums, minNum, maxNum);
    for (const int& e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

void counting_sort(std::vector<int>& nums, int minNum, int maxNum)
{
    const int n = nums.size();
    const int m = maxNum - minNum + 1;
    std::vector<int> countingArr(m, 0);
    std::vector<int> sortedArr(n, 0);

    for (int idx = 0; idx < n; ++idx)
    {
        countingArr[nums[idx] - minNum]++;
    }

    countingArr[0]--;
    for (int idx = 1; idx < m; ++idx)
    {
        countingArr[idx] += countingArr[idx - 1];
    }

    for (int idx = n - 1; idx >= 0; --idx)
    {
        sortedArr[countingArr[nums[idx] - minNum]--] = nums[idx];
    }

    nums = sortedArr;
}
