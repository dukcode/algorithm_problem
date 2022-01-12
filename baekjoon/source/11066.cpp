// 11066.cpp -- 파일 합치기
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

using namespace std;

const int INF = 987654321;

int cache[500][500];

int n;
int pages[501];

int pSum[500];

void preCalc(void);
int getMinCost(int start, int end);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("11066_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> pages[i];
        }

        preCalc();
        cout << getMinCost(0, n - 1) << '\n';
    }

    return 0;
}

void preCalc(void)
{
    // 0 - (i - 1)까지의 합
    pSum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        pSum[i] = pSum[i - 1] + pages[i - 1];
    }
}

int getMinCost(int start, int end)
{
    int& ret = cache[start][end];
    if (ret != -1)
    {
        return ret;
    }

    // base case
    if (start == end)
    {
        return ret = 0;
    }

    if (start + 1 == end)
    {
        return ret = pages[start] + pages[end];
    }

    ret = INF;
    for (int mid = start; mid < end; ++mid)
    {
        ret = min(ret, getMinCost(start, mid) + getMinCost(mid + 1, end) + (pSum[end + 1] - pSum[start]));
    }

    return ret;
}
