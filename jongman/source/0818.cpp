// 0818.cpp -- 우물을 기어오르는 달팽이 문제를 해결하는 동적 계획법 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_N = 10;

int n; int m;
int cache[MAX_N][2 * MAX_N + 1];

int climb(int days, int climbed);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    cin >> n >> m;

    cout << double(climb(0, 0)) / pow(2, m) << '\n';

    return 0;
}

int climb(int days, int climbed)
{
    if (days == m)
    {
        return climbed >= n ? 1 : 0;
    }

    int& ret = cache[days][climbed];
    if (ret != -1)
    {
        return ret;
    }

    return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}
