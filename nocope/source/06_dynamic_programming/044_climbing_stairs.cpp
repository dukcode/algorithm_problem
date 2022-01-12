// [leetcode 70] Climbing Stairs
#include <vector>

int climbStairs(int n)
{
    static std::vector<int> cache{1, 1};
    int size = cache.size();

    if (n < size)
    {
        return cache[n];
    }

    int num = 0;
    for (int i = size; i <= n; ++i)
    {
        num = cache[i - 2] + cache[i - 1];
        cache.emplace_back(num);
    }

    return num;
}
