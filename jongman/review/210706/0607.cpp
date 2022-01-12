// 0607.cpp -- 여행하는 외판원 문제를 해결하는 재귀 호출 알고리즘
#include <vector>
#include <algorithm>

int n;

bool taken[10];

double distance[10][10];

double getShortestPathLen(vector<int>& path, double currentLen)
{
    // base case
    if (path.size() == n)
    {
        return currentLen + distance[path.back()][path[0]];
    }

    double ret = INF;
    for (int next = 0; next < n; ++next)
    {
        if (taken[next])
        {
            continue;
        }

        int here = path.back();

        taken[next] = true;
        path.push_back(next);
        ret = min(ret, getShortestPathLen(path, currentLen + distance[here][next]));
        taken[next] = false;
        path.pop_back();
    }

    return ret;
}
