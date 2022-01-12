// 0811.cpp -- 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (1)
#include <vector>
#include <algorithm>

vector<int> A;

int cache[100];

int lis(int start)
{
    int& ret = cache[start];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;

    for (int i = 1; start + i < A.size(); i++)
    {
        if (A[start] < A[start + i])
        {
            ret = max(ret, lis(start + i) + 1);
        }
    }

    return ret;
}
