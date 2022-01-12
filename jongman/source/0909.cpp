// 0909.cpp -- k번째 신호를 계산하는 알고리즘
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 1000000000 + 100;

int bino[201][201];

void calcBino(void);
string kth(int n, int m, int skip);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;
    int skip; cin >> skip;

    calcBino();
    cout << kth(n, m, skip);

    return 0;
}

void calcBino(void)
{
    memset(bino, 0 ,sizeof(bino));

    for (int i = 0; i <= 200; ++i)
    {
        bino[i][0] = bino[i][i] = 0;
        for (int j = 1; j < i; ++j)
        {
            bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }
}

string kth(int n, int m, int skip)
{
    if (n == 0)
    {
        return string(m, 'o');
    }

    if (bino[n + m - 1][n - 1] > skip)
    {
        return "-" + kth(n - 1, m, skip);
    }

    return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}
