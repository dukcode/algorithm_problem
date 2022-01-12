// 0820.cpp -- 직접 비대칭 타일링의 수를 세는 동적 계획법 알고리즘
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[101];
int asymCache[101];

int tiling(int width);
int asymTiling(int width);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0820_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));
    memset(asymCache, -1, sizeof(asymCache));

    int testCase; cin >> testCase;
    while (testCase--)
    {
        int n; cin >> n;

        cout << asymTiling(n) << '\n';
    }

    return 0;
}

int tiling(int width)
{
    int& ret = asymCache[width];
    if (ret != -1)
    {
        return ret;
    }

    // base case
    if (width <= 2)
    {
        return ret = width;
    }

    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

int asymTiling(int width)
{
    // base case
    if (width <= 2)
    {
        return 0;
    }

    int& ret = cache[width];
    if (ret != -1)
    {
        return ret;
    }

    ret = asymTiling(width - 2) % MOD;
    ret = (ret + asymTiling(width - 4)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;

    return ret;
}

