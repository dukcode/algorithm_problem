// 2193.cpp -- 이친수
#include <cstdio>
#include <iostream>
#include <cstring>

long long cache[91];
int n;

long long getNumberOfCases(int n);

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("2194_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << getNumberOfCases(n) << '\n';

    return 0;
}


long long getNumberOfCases(int num)
{
    // base case
    if (num <= 1)
    {
        return num;
    }

    long long& ret = cache[num];
    if (ret != -1)
    {
        return ret;
    }

    return ret = getNumberOfCases(num - 1) + getNumberOfCases(num - 2);
}
