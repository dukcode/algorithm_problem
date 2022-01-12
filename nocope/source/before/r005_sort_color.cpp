#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void swap(int& lhs, int& rhs)
    {
        int temp = lhs;
        lhs = rhs;
        rhs = temp;
    }

    void sortColors(vector<int>& nums)
    {
        const int n = nums.size();

        int idxZero = 0;
        int idxTwo = n - 1;
        int i = 0;

        while (i <= idxTwo)
        {
            if (nums[i] == 0)
            {
                swap(nums[idxZero], nums[i]);
                i++;
                idxZero++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[idxTwo]);
                idxTwo--;
            }
            else
            {
                i++;
            }
        }
    }
};

int main(void)
{

    return 0;
}
