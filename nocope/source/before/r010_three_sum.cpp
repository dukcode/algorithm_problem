#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        const int n = nums.size();
        vector<vector<int>> res;

        if (n < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int lo = 0; lo < n - 2; lo++)
        {
            int target = -nums[lo];
            if (target < 0)
            {
                break;
            }

            int mid = lo + 1;
            int hi = n - 1;

            int sum;
            while (mid < hi)
            {
                int sum = nums[mid] + nums[hi];

                if (sum == target)
                {
                    vector<int> triplet{nums[lo], nums[mid], nums[hi]};
                    res.emplace_back(triplet);

                    while (mid < hi && triplet[1] == nums[mid])
                    {
                        mid++;
                    }

                    while (mid < hi && triplet[2] == nums[hi])
                    {
                        hi--;
                    }
                }
                else if (sum < target)
                {
                    mid++;
                }
                else if (sum > target)
                {
                    hi--;
                }
            }

            while (lo < n - 2 && nums[lo] == nums[lo + 1])
            {
                lo++;
            }
        }

        return res;
    }
};

int main(void)
{

    return 0;
}
