// 9461.cpp -- 파도반 수열
#include <cstdio>
#include <iostream>
#include <cstring>

int n;

long long cache[101];

long long solve(int num);

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("9461_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}

// 1 0 0 1 0 (1) 1 1 2 2 3 4 5 7 9 12 16 ...
long long solve(int num)
{
    // base case 1
    if (num == -1 || num == -4)
    {
        return 1;
    }

    // base case 2
    if (num <= 0)
    {
        return 0;
    }

    long long& ret = cache[num];
    if (ret != -1)
    {
        return ret;
    }

    return ret = solve(num - 1) + solve(num - 5);
}
