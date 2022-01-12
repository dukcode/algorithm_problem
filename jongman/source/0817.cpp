// 0817.cpp -- 삼각형 위의 최대 경로의 수를 찾는 동적 계획법 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[100][100];
int countCache[100][100];

int n;
int triangle[100][100];

int path(int y, int x);
int count(int y, int x);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0817_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));
        memset(triangle, 0, sizeof(triangle));

        cin >> n;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < y + 1; x++)
            {
                cin >> triangle[y][x];
            }
        }

        cout << count(0, 0) << '\n';
    }

    return 0;
}

int path(int y, int x)
{
    int& ret = cache[y][x];

    if (ret != -1)
    {
        return ret;
    }

    if (y == n - 1)
    {
        return ret = triangle[y][x];
    }


    return ret = max( path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x)
{
    int& ret = countCache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    // base case
    if (y == n - 1)
    {
        return ret = 1;
    }

    ret = 0;

    if (path(y + 1, x) >= path(y + 1, x + 1))
    {
        ret += count(y + 1, x);
    }

    if (path(y + 1, x) <= path(y + 1, x + 1))
    {
        ret += count(y + 1, x + 1);
    }

    return ret;
}
