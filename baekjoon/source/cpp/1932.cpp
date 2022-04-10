// 1932.cpp -- 정수 삼각형
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int board[500][500];

int cache[500][500];

int getMaxValue(int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("1932_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x <= y; x++)
        {
            cin >> board[y][x];
        }
    }

    cout << getMaxValue(0, 0) << '\n';

    return 0;
}

int getMaxValue(int y, int x)
{
    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    // base case;
    if (y == n - 1)
    {
        return ret =  board[y][x];
    }

    return ret = max(getMaxValue(y + 1, x), getMaxValue(y + 1, x + 1)) + board[y][x];
}
