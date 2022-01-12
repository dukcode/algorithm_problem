// [leetcode 724] Find Pivot Index
#include <vector>

int pivotIndex(vector<int>& nums)
{
    const int n = nums.size();

    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < n; ++i)
    {
        rightSum += nums[i];
    }

    int pastPivotNum = 0;           // 깔끔하게 할라면 for문 내용 먼저 쓰고 pastPivotNum 필요성 알기. 그 후 pastPivotNum 초기화 숫자 고려
    for (int pivot = 0; pivot < n; ++pivot)
    {
        rightSum -= nums[pivot];
        leftSum += pastPivotNum;
        pastPivotNum = nums[pivot];

        if (leftSum == rightSum)
        {
            return pivot;
        }
    }

    return -1;
}
