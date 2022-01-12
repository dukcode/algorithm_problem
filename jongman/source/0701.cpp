// 0701.cpp -- 1부터 n까지의 합을 구하는 분할 정복 알고리즘
#include <cstdio>
#include <iostream>

#define endl '\n'

using namespace std;

int fastSum(int n);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("0701_input.txt", "r", stdin);

    int n; cin >> n;
    cout << fastSum(n) << endl;

    return 0;
}

int fastSum(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    if (n % 2 == 1)
    {
        return fastSum(n - 1) + n;
    }

    return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}
