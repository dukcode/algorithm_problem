#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int n = nums.size();

        int leftSum = 0;
        int rightSum = 0;
        for (int idx = 0; idx < n; idx++)
        {
            rightSum += nums[idx];
        }

        int pivot = 0;
        while (pivot <= n)
        {
            if (pivot != 0)
            {
                leftSum += nums[pivot - 1];
            }
            rightSum -= nums[pivot];

            if (leftSum == rightSum)
            {
                return pivot;
            }
            
            pivot++;
        }

        return -1;
    }
};

int main(void)
{

    return 0;
}
