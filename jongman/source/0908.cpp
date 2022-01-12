// 0908.cpp -- k - 1개 건너뛰고 첫 번째 신호를 출력하는 알고리즘
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int M = 1000000000 + 100;

int skip;

int bino[201][201];

void calcBino(void);
void gernerate(int n, int m, string s);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    calcBino();

    int n; cin >> n;
    int m; cin >> m;
    cin >> skip;

    string s;
    gernerate(n, m, s);

    return 0;
}

void calcBino(void)
{
    memset(bino, 0, sizeof(bino));

    for (int i = 0; i <= 200; ++i)
    {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            bino[i][j] = bino[i - 1][j - 1] + bino[i - 1][j];
        }
    }
}

void gernerate(int n, int m, string s)
{
    if (skip < 0)
    {
        return;
    }

    if (bino[n + m][m] <= skip)
    {
        skip -= bino[n + m][m];
        return;
    }

    if (n == 0 && m == 0)
    {
        if (skip == 0)
        {
            cout << s << '\n';
        }
        --skip;
        return;
    }

    if (n != 0)
    {
        gernerate(n - 1, m, s + "-");
    }

    if (m != 0)
    {
        gernerate(n, m - 1, s + "o");
    }
}
