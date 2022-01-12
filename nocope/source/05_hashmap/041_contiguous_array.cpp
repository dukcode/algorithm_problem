// [leetcode 525] Contiguous Array
#include <vector>
#include <unordered_map>
#include <algorithm>

int findMaxLength(std::vector<int>& nums)
{
    const int n = nums.size();
    std::unordered_map<int, int> m; // <cumulativeSum, idx>
    m.emplace(0, -1);

    int res = 0;
    int cumulativeSum = 0;

    for (int idx = 0; idx < n; ++idx)
    {
        cumulativeSum += (nums[idx] == 1 ? 1 : -1);

        if (m.find(cumulativeSum) != m.end())
        {

            res = std::max(res, idx - m[cumulativeSum]);
        }
        else
        {
            m[cumulativeSum] = idx;
        }
    }

    return res;
}
