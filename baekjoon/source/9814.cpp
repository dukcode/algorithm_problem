// 9814.cpp -- 신나는 함수 실행
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int cache[51][51][51];

int w(int a, int b, int c);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("9814_input.txt", "r", stdin);


    memset(cache, -1, sizeof(cache));

    int a; int b; int c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1)
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
        cin >> a >> b >> c;
    }

    return 0;
}

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    int& ret = cache[a][b][c];
    if (ret != -1)
    {
        return ret;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return ret = w(20, 20, 20);
    }

    if (a < b && b < c)
    {
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }

    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
