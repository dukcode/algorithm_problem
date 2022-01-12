// 2156.cpp -- 포도주 시식
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int glass[10001];

int cache[10001];

int getMaxValue(int toPick);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("2156_input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> glass[i];
    }

    memset(cache, -1, sizeof(cache));
    cout << getMaxValue(n) << '\n';

    return 0;
}

int getMaxValue(int toPick)
{
    // base case
    if (toPick <= 0)
    {
        return 0;
    }

    int& ret = cache[toPick];
    if (ret != -1)
    {
        return ret;
    }

    ret = max(getMaxValue(toPick - 3) + glass[toPick - 1] + glass[toPick], getMaxValue(toPick - 2) + glass[toPick]);
    ret = max(ret, getMaxValue(toPick - 1));

    return ret;
}
