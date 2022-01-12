#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    const int n = nums.size();
    std::unordered_map<int, int> m;
    std::vector<int> res;

    for (int idx = 0; idx < n; ++idx)
    {
        int diff = target - nums[idx];
        if (m.find(diff) != m.end())
        {
            res.emplace_back(idx);
            res.emplace_back(m[diff]);
            break;
        }
        else
        {
            m.emplace(nums[idx], idx);
        }
    }

    return res;
}

int main(void)
{
    std::vector<int> v{1, 2, 3, 4};


    return 0;
}
