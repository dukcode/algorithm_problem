// 0808.cpp -- 삼각형 위의 최대 경로 문제를 푸는 메모이제이션 코드 (1)
#include <cstdio>
#include <iostream>

using namespace std;

int n; int triangle[100][100];
int cache[100][100][MAX_NUMBER * 100 + 1];

int path(y, x, sum);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("", "r", stdin);

    return 0;
}

int path(y, x, sum)
{
    // base case
    if (y == n - 1)
    {
        return sum + triangle[y][x];
    }

    int& ret = cache[y][x][sum];

    if (ret != -1)
    {
        return ret;
    }

    sum += triangle[y][x];

    return ret = max(path(y + 1, x, sum), path(y + 1, x + 1, sum));
}
