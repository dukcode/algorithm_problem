// 1003.cpp -- 피보나치 함
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;

int cache[41];

int fibonacci(int num);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("1003_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> n;
        cout << fibonacci(n - 2) << ' ' << fibonacci(n - 1) << '\n';
    }

    return 0;
}

int fibonacci(int num)
{
    if (num == -1)
    {
        return 0;
    }
    if (num <= 1)
    {
        return 1;
    }

    int& ret = cache[num];
    if (ret != -1)
    {
        return ret;
    }

    return ret = fibonacci(num - 1) + fibonacci(num - 2);
}
