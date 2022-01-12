#include <iostream>
#include <vector>

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        const int n = nums.size();

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int pivot = (left + right) / 2;
            int num = nums[pivot];
            int numNext = nums[pivot + 1];

            if (num < numNext)
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot;
            }
        }

        return left;
    }

};

int main(void)
{

    return 0;
}
