// 0809.cpp -- 삼각형 위의 최대 경로 문제를 푸는 동적 계획법 알고리즘 (2)
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n; int triangle[100][100];
int cache[100][100];

int path(int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("", "r", stdin);

    return 0;
}

int path(int y, int x)
{
    // base case
    if (y == n - 1)
    {
        return triangle[y][x];
    }

    int& ret = cache[y][x];

    if (ret != -1)
    {
        return ret;
    }

    return ret = triangle[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}
