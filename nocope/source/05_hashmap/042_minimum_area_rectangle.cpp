// [leetcode 939] Minimum Area Rectangle
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <cstdlib>

const int MAX_INT = std::numeric_limits<int>::max();

int minAreaRect(std::vector<std::vector<int>>& points)
{
    const int n = points.size();
    if (n < 4)
    {
        return 0;
    }

    // hashMap 안에 hashSet 아이디어!!!!!!!!!!!
    std::unordered_map<int, unordered_set<int>> m;

    for (int idx = 0; idx < n; ++idx)
    {
        m[points[idx][0]].emplace(points[idx][1]);
    }

    int res = MAX_INT;
    for (int i = 0; i < n; ++i)
    {
        int x1 = points[i][0];
        int y1 = points[i][1];

        for (int j = i + 1; j < n; ++j)
        {
            int x2 = points[j][0];
            int y2 = points[j][1];

            if (x1 == x2 || y1 == y2)
            {
                continue;
            }

            if (m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x2].end())
            {
                res = min(res, std::abs((x2 - x1) * (y2 - y1)));
            }
        }
    }

    return res == MAX_INT ? 0 : res;
}
