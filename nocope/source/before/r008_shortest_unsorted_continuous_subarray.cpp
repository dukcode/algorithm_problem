#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(const vector<int>& nums)
    {
        const int n = nums.size();
        int start = -1;
        int end = -2;

        int maxValue = numeric_limits<int>::min();
        int minValue = numeric_limits<int>::max();
        for (int idx = 0; idx < n; idx++)
        {
            maxValue = max(maxValue, nums[idx]);
            if (maxValue > nums[idx])
            {
                end = idx;
            }

            minValue = min(minValue, nums[n - 1 - idx]);
            if (minValue < nums[n - 1 - idx])
            {
                start = n - 1 - idx;
            }
        }

        return end - start + 1;
    }
};

int main(void)
{

    return 0;
}
