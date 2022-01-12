#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    static int findDuplicate(vector<int>& nums)
    {
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            int num = abs(nums[idx]);
            if (nums[num - 1] < 0)
            {
                return num;
            }
            else
            {
                nums[num - 1] *= -1;
            }
        }

        return -1;
    }
};

int main(void)
{
    vector<int> nums{1, 3, 2, 3, 4, 5, 6};

    cout << Solution::findDuplicate(nums) << endl;

    return 0;
}
