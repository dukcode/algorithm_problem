// 11727.cpp -- 2xn 타일링2
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10007;

int cache[1001];

int getCountOfCases(int width);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    int n; cin >> n;

    cout << getCountOfCases(n) << '\n';

    return 0;
}

int getCountOfCases(int width)
{
    if (width <= 1)
    {
        return 1;
    }
    
    int& ret = cache[width];
    if (ret != -1)
    {
        return ret;
    }

    return ret = (getCountOfCases(width - 1) + 2 * getCountOfCases(width - 2)) % MOD;
}
