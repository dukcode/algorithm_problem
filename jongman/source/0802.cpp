// 0802.cpp -- 메모이제이션을 이용한 이항 계수의 계산
#include <iostream>
#include <cstdio>

using namespace std;

int cache[30][30];
int bino(int n, int r);

int main(void)
{
    for (int y = 0; y < 30; y++)
    {
        for (int x = 0; x < 30; x++)
        {
            cache[y][x] = -1;
        }
    }
    int testCase; cin >> testCase;
    while (testCase--)
    {
        int n; int r; cin >> n >> r;
        cout << bino(n, r) << '\n';
    }

    return 0;
}

int bino(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }

    if (cache[n][r] != -1)
    {
        return cache[n][r];
    }

    return cache[n][r] = bino(n - 1, r - 1) + bino(n - 1, r);
}
