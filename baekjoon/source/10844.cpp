// 10844.cpp -- 쉬운 계단 수
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int cache[101][10];

int n;

void preCalc(void);
int getStairNum(int length, int lastNum);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //freopen("10844_input.txt", "r", stdin);

    preCalc();

    cin >> n;

    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        ans = (ans + getStairNum(n, i)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}

void preCalc(void)
{
    memset(cache, -1, sizeof(cache));

    cache[1][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        cache[1][i] = 1;
    }
}

int getStairNum(int length, int lastNum)
{
    int& ret = cache[length][lastNum];
    if (ret != -1)
    {
        return ret;
    }

    if (lastNum == 0)
    {
        return ret = getStairNum(length - 1, 1) % MOD;
    }

    if (lastNum == 9)
    {
        return ret = getStairNum(length - 1, 8) % MOD;
    }


    return ret = (getStairNum(length -1, lastNum - 1) + getStairNum(length - 1, lastNum + 1)) % MOD;
}
