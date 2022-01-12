// 11653.cpp -- 소인수분해
#include <cstdio>
#include <iostream>

using namespace std;

void solve(int n, int divider);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    solve(n, 2);

    return 0;
}

void solve(int n, int divider)
{
    if (n == 1)
    {
        return;
    }

    while (n % divider == 0)
    {
        cout << divider << '\n';
        n /= divider;
    }

    solve(n, divider + 1);
}
