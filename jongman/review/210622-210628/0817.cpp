// 0817.cpp -- 삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘
#include <cstdio>
#include <iostream>

using namespace std;

int cache[100][100];
int countCache[100][100];

int n;
int board[100][100];

int path(int y, int x);
int count(int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0817_input.txt", "r", stdin);

    cin >> n;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x <= y; ++x)
        {
            cin >> board[y][x];
        }
    }



    return 0;
}

int path(int y, int x)
{
    // base case
    if (y == n - 1)
    {
        return board[y][x];
    }

    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + board[y][x];
}

int count(int y, int x)
{
    // base case
    if (y == n - 1)
    {
        return 1;
    }

    int& ret = countCache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;

    if (path(y + 1, x) >= path(y + 1, x + 1))
    {
        ret += count(y + 1, x);
    }

    if (path(y + 1, x) >= path(y + 1, x + 1))
    {
        ret += count(y + 1, x);
    }

    return ret;
}
