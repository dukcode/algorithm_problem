// 2748.cpp -- 피보나치 수 2
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long cache[91];

long long fibonacci(int n);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    int n; cin >> n;

    cout << fibonacci(n) << '\n';

    return 0;
}

long long fibonacci(int n)
{
    long long& ret = cache[n];
    if (ret != -1)
    {
        return ret;
    }

    if (n == 0 || n == 1)
    {
        return ret = n;
    }

    return ret = fibonacci(n - 1) + fibonacci(n - 2);
}
