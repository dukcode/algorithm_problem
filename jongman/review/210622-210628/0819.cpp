// 0819.cpp -- ASYMTILING
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[101];

int tiling(int width);
int asymTiling(int width);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0819_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

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
    int& ret = cache[width];
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
    if (width % 2 == 1)
    {
        return (tiling(width) - tiling(width / 2)) % MOD;
    }
    
    int ret = tiling(width);
    ret = (ret - tiling(width / 2) + MOD) % MOD;
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;

    return ret;
}
