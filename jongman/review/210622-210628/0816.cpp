// 0816.cpp --TILING2
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[101];

int tiling(int n);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0816_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    int testCase; cin >> testCase;

    while (testCase--)
    {
        int n; cin >> n;

        cout << tiling(n) << '\n';
    }

    return 0;
}

int tiling(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int& ret = cache[n];
    if (ret != -1)
    {
        return ret;
    }

    ret = (tiling(n - 1) + tiling(n - 2)) % MOD;

    return ret;
}
