#include <iostream>

// 대전제 : 왼쪽 올라가고 오른쪽 내려가면 사이엔 항상 peak가 있다.
int findPeakElement(int* nums, int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int pivot = (left + right) / 2;
        int num = nums[pivot];
        int nextNum = nums[pivot + 1];

        if (num < nextNum)
        {
            // 안쪽
            left = pivot + 1;
        }
        else
        {
            // 안쪽
            right = pivot;
        }
    }

    return left;
}
