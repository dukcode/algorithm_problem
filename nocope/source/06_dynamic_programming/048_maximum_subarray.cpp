#include <vector>
#include <limits>
#include <algorithm>

// 위의 방법 아래 방법 차이?
int maxSubArray(std::vector<int>& nums)
{
    const int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }

    std::vector<int> cache(n, 0);
    cache[0] = nums[0];

    int ret = cache[0];
    for (int idx = 1; idx < n; ++idx)
    {
        cache[idx] = max(nums[idx], cache[idx - 1] + nums[idx]);
        ret = std::max(ret, cache[idx]);
    }

    return ret;
}

int maxSubArray(std::vector<int>& nums)
{
    const int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }

    int sum = 0;
    int res = std::numeric_limits<int>::min();
    for (int idx = 0; idx < n; ++idx)
    {
        sum += nums[idx];
        res = std::max(res, sum);
        sum = sum < 0 ? 0 : sum;
    }

    return res;
}
