// 0801.cpp -- 재귀 호출을 이용한 이항 계수의 계산
#include <iostream>
#include <cstdio>

using namespace std;

int bino(int n, int r);

int main(void)
{
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

    return bino(n - 1, r - 1) + bino(n - 1, r);
}
