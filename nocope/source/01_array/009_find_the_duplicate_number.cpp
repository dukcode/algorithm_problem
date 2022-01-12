// [leetcode 287] Fint the Duplicate Number
#include <vector>

int findDuplicate(std::vector<int>& nums)
{
    const int n = nums.size();
    
    int idx = 0;
    for (int i = 0; i < n; ++i)
    {
        idx = std::abs(nums[i]);
        if (nums[idx] < 0)
        {
            return idx;
        }
        
        nums[idx] *= -1;
    }

    return -1;
}
