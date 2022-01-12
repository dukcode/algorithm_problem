// [leetcode 746] Min Cost Climbing Stairs
#include <vector>
#include <array>
#include <algorithm>

int minCostClimbingStairs(vector<int>& cost)
{
    static std::array<int, 1000 + 1> cache;
    const int n = cost.size();
    cost.emplace_back(0);

    for (int idx = 0; idx <= n; ++idx)
    {
        if (idx <= 1)
        {
            cache[idx] = cost[idx];
            continue;
        }

        cache[idx] = min(cache[idx - 2], cache[idx - 1]) + cost[idx];
    }

    return cache[n];
}
