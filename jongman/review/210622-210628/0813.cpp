// 0813.cpp -- JLIS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

int cache[101][101];

const long long NEGINF = numeric_limits<long long>::min();

int n; int m;
int A[100]; int B[100];

int jlis(int indexA, int indexB);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0813_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> n >> m;
        for (int i = 0 ; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> B[i];
        }

        cout << jlis(-1, -1) - 2 << '\n';
    }

    return 0;
}

int jlis(int indexA, int indexB)
{
    int& ret = cache[indexA + 1][indexB + 1];
    if (ret != -1)
    {
        return ret;
    }

    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);

    long long maxValue = max(a, b);

    ret = 2;
    for (int next = indexA + 1; next < n; ++next)
    {
        if (maxValue < A[next])
        {
            ret = max(ret, jlis(next, indexB) + 1);
        }
    }

    for (int next = indexB + 1; next < m; ++next)
    {
        if (maxValue < B[next])
        {
            ret = max(ret, jlis(indexA, next) + 1);
        }
    }

    return ret;
}
