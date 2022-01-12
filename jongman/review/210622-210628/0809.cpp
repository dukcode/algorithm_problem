// 0809.cpp -- TRIANGLEPATH
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int board[100][100];

int cache[100][100];

int getMaxPoint(int y, int x);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0809_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> n;

        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x <= y; ++x)
            {
                cin >> board[y][x];
            }
        }

        cout << getMaxPoint(0, 0) << '\n';
    }

    return 0;
}

int getMaxPoint(int y, int x)
{
    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    if (y == n - 1)
    {
        return ret = board[y][x];
    }

    return ret = max(getMaxPoint(y + 1, x), getMaxPoint(y + 1, x + 1)) + board[y][x];
}
