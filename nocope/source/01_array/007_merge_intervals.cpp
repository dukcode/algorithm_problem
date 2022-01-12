// [leetcode 56] Merge Intervals
#include <vector>
#include <algorithm>

std::vector<std::vector<int> merge(std::vector<std::vector<int>>& intervals)
{
    const int n = intervals.size();
    std::vector<vector<int>> res;

    std::sort(intervals.begin(), intervals.end());

    int i = 0;
    while (i < n)       // 합치기 : 걍 기억해 2중while문이 제일 깔끔
    {
        int left = intervals[i][0];
        int right = intervals[i][1];
        i++;

        while (i < n && right >= intervals[i][0])
        {
            right = std::max(right, intervals[i][1]);
            i++;
        }

        res.push_back({left, right});
    }

    return res;
}
