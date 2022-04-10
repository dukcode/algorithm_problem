// 11054.cpp -- 가장 긴 바이토닉 부분 수열
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int A[1000];

int cacheInc[1000];
int cacheDec[1000];

int solve(void);
int increase(int start);
int decrease(int end);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("11054_input.txt", "r", stdin);

    memset(cacheInc, -1, sizeof(cacheInc));
    memset(cacheDec, -1, sizeof(cacheDec));

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cout << solve() << '\n';

    return 0;
}

int solve()
{
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret = max(ret, increase(i) + decrease(i) - 1);
    }

    return ret;
}

int decrease(int start)
{
    int& ret = cacheInc[start];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (A[start] > A[next])
        {
            ret = max(ret , decrease(next) + 1);
        }
    }

    return ret;
}

int increase(int end)
{
    int& ret = cacheDec[end];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int before = end - 1; before >= 0; --before)
    {
        if (A[before] < A[end])
        {
            ret = max(ret , increase(before) + 1);
        }
    }

    return ret;
}
