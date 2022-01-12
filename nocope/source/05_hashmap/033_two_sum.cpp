// [leetcode 1] Two Sum
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target)
{
    const int n = nums.size();
    unordered_map<int, int> m;
    
    for (int idx = 0; idx < n; ++idx)
    {
        if (m.find(nums[idx]) != m.end())
        {
            return vector<int> {m[nums[idx]], idx};
        }
        m.emplace(target - nums[idx], idx);
    }

    return vector<int>();
}
