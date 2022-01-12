// 0810.cpp
#include <vector>

int cache[101];
int A[100];

int n;

int lis(int start)
{
    int& ret = cache[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (start = -1 || A[start] < A[i])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}
