// [leetcode 283] Move Zeroes
#include <vector>

void moveZeroes(vector<int>& nums)
{
    const int n = nums.size();

    int writingIdx = 0;
    for (int readingIdx = 0; readingIdx < n; ++readingIdx)
    {
        if (nums[readingIdx] != 0)
        {
            nums[writingIdx] = nums[readingIdx];
            writingIdx++;
        }
    }

    while (writingIdx < n)
    {
        nums[writingIdx] = 0;
        writingIdx++;
    }
}
