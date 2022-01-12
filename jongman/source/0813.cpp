// 0813.cpp -- 합친 LIS 문제를 해결하는 동적 계획법 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int n; int m;
int A[100]; int B[100];
int cache[101][101];

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
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        cin >> n >> m;
        for (int i = 0; i < n; i++)
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

    long long a = indexA == -1 ? NEGINF : A[indexA];
    long long b = indexB == -1 ? NEGINF : B[indexB];

    long long maxElement = max(a, b);

    ret = 2;

    for (int nextA = indexA + 1; nextA < n; nextA++)
    {
        if (maxElement < A[nextA])
        {
            ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }

    for (int nextB = indexB + 1; nextB < m; nextB++)
    {
        if (maxElement < B[nextB])
        {
            ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }

    return ret;
}
