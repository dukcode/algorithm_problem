// [leetcode 1] Two Sum
#include <vector>
#include <algorithm>

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> original(nums);
    const std::size_t n = nums.size();
    std::sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;

    while (left != right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
            break;
        }

        if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    int firstVal = nums[left];
    int secondVal = nums[right];

    int firstIdx;
    int secondIdx;
    for (int i = 0; i < n; ++i)
    {
        if (firstVal == original[i])
        {
            firstIdx = i;
            break;
        }

    }
    
    for (int i = n - 1; i >= 0; --i)
    {
        if (secondVal == original[i])
        {
            secondIdx = i;
            break;
        }
    }

    return vector<int> {std::min(firstIdx, secondIdx), std::max(firstIdx, secondIdx)};
}
