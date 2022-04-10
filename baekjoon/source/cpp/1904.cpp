// 1904.cpp -- 01타
#include <cstdio>
#include <iostream>

using namespace std;

const int MOD = 15746;

int n;
int ans[1000001];

void preCalc(void);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("1904_input.txt", "r", stdin);

    cin >> n;
    preCalc();

    cout << ans[n] << '\n';

    return 0;
}

void preCalc(void)
{
    ans[1] = 1;
    ans[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        ans[i] = (ans[i - 1] + ans[i -2]) % MOD;
    }
}
