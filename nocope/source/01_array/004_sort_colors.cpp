// [leetcode 75] Sort Colors
#include <vector>
#include <algorithm>

void sortColors(vector<int>& nums)
{
    const int n = nums.size();

    int left = 0;
    int right = n - 1;

    int i = 0;
    while (i <= right)  //  투포인터로 앞뒤 swap 필요할 때 앞에 swap은 둘다 +이지만 뒤에서 swap 때는 처리되지 않은 값 넘어오기 때문에 right만 -
    {
        if (nums[i] == 0)
        {
            std::swap(nums[left], nums[i]);
            left++;
            i++;
        }
        else if (nums[i] == 2)
        {
            std::swap(nums[i], nums[right]);
            right--;
        }
        else
        {
            i++;
        }
    }
}
