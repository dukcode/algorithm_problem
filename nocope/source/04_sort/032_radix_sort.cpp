#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <algorithm>

const int maxDigit = 5;
std::array<int, 10> cache;

void countingSort(std::vector<int>& nums, int digit)
{
    static std::array<int, 10> cache;
    cache.fill(0);

    const int n = nums.size();

    int num;
    for (int i = 0; i < n; ++i)
    {
        // 최적화 가능
        num = nums[i];
        for (int j = 0; j < digit; ++j)
        {
            num /= 10;
        }
        num %= 10;

        cache[num]++;
    }

    cache[0]--;
    for (int i = 1; i < 10; ++i)
    {
        cache[i] += cache[i - 1];
    }

    std::vector<int> sortedArr(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        // 최적화 가능
        num = nums[i];
        for (int j = 0; j < digit; ++j)
        {
            num /= 10;
        }
        num %= 10;
        sortedArr[cache[num]--] = nums[i];
    }

    nums = sortedArr;
}


// O((n + 진수) * 자릿수)
void radixSort(std::vector<int>& nums)
{
    for (int digit = 0; digit < maxDigit; ++digit)
    {
        countingSort(nums, digit);
    }
}


int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99999);

    std::vector<int> nums;
    for (int i = 0; i < 50; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    radixSort(nums);

    for (const int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
