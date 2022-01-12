#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        const int n = nums.size();
        
        vector<int> temp;
        copy(nums.begin(), nums.end(), back_inserter(temp));
        sort(temp.begin(), temp.end());

        int left = 0;
        int right = n - 1;
        int indexL = 0;
        int indexR = 0;

        int sum = 0;
        while (left < right)
        {
            sum = temp[left] + temp[right];

            if (sum == target)
            {
                indexL = left;
                indexR = right;
                break;
            }
            else if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }

        }

        vector<int> ret;
        for (int idx = 0; idx < n; ++idx)
        {
            if (nums[idx] == temp[indexL] || nums[idx] == temp[indexR])
            {
                ret.emplace_back(idx);
            }

            if (ret.size() == 2)
            {
                break;
            }
        }
        
        return ret;
    }
};

int main(void)
{

    return 0;
}
