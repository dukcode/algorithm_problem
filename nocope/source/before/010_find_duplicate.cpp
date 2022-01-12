#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int findDuplicate(std::vector<int> nums);

int main(void)
{
    std::vector<int> nums{5, 4, 3, 2, 1, 3};

    std::cout << findDuplicate(nums) << std::endl;
    
    return 0;
}

int findDuplicate(std::vector<int> nums)
{
    const int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int num = std::abs(nums[i]);
        if (nums[num - 1] < 0)
        {
            return num;
        }
        
        nums[num - 1] *= -1;
    }

    return -1;
}
