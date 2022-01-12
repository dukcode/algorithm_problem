#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static void moveZeros(vector<int>& nums)
    {
        int n = nums.size();

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
};

int main(void)
{
    vector<int> v{1, 0, 2, 0, 3, 0, 4, 0};

    Solution::moveZeros(v);
    for (const auto& e : v)
    {
        cout << e << ' ';
    }
    cout << '\n';

    return 0;
}
