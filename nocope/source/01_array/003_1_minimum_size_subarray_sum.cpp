// [leetcode 209] Minimum Size Subarray Sum
#include <vector>
#include <algorithm>
#include <limits>

int minSubArrayLen(int target, std::vector<int>& nums)
{
    const int n = nums.size();

    int start = 0;
    int minLen = std::numeric_limits<int>::max();

    int sum = 0;
    for (int end = 0; end < n; ++end)
    {
        sum += nums[end];

        while (sum >= target)           // 투포인터 for문 돌고 while로 left땡겨주기
        {
            minLen = std::min(minLen, end - start + 1);
            sum -= nums[start];
            start++;
        }
    }

    return minLen == std::numeric_limits<int>::max() ? 0 : minLen;
}
