// 0821.cpp -- 폴리노미오의 수 구하기
#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 10 * 1000 * 1000;

int cache[101][101];

int poly(int n, int first);

int main(void)
{

    return 0;
}

int poly(int n, int first)
{
    int& ret = cache[n][first];

    if (ret != -1)
    {
        return ret;
    }

    if (n == first)
    {
        return ret = 1;
    }

    ret = 0;

    for (int second = 1; second < n - first; second++)
    {
        // ret += (second + first - 1) * poly(n - first, second);
        int add = second + first - 1;
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %- MOD;
    }

    return ret;
}
