// [leetcode 152] Maximum Product Subarray
#include <vector>

int maxProduct(std::vector<int>& nums)
{
    const int n = nums.size();

    std::vector<int> minCache(n);
    std::vector<int> maxCache(n);

    minCache[0] = maxCache[0] = nums[0];

    int res = nums[0];
    for (int idx = 1; idx < n; ++idx)
    {
        minCache[idx] = std::min({minCache[idx - 1] * nums[idx], maxCache[idx - 1] * nums[idx], nums[idx]});
        maxCache[idx] = std::max({minCache[idx - 1] * nums[idx], maxCache[idx - 1] * nums[idx], nums[idx]});

        res = std::max({res, minCache[idx], maxCache[idx]});
    }

    return res;
}
