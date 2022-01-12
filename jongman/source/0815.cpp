// 0815.cpp -- Quantization 문제의 구현
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n; int s;
int A[100]; int pSum[101]; int pSqSum[101]; // pSum[a] == a - 1까지의 합
int cache[101][11];

void preCalc();
int minError(int lo, int hi);
int quantize(int from, int parts);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0815_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> n >> s;

        memset(A, 0, sizeof(A));
        memset(pSum, 0, sizeof(pSum));
        memset(pSqSum, 0, sizeof(pSqSum));
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        preCalc();
        cout << quantize(0, s) << '\n';
    }

    return 0;
}

void preCalc()
{
    sort(A, A + n);

    pSum[0] = 0;
    pSqSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pSum[i] = pSum[i - 1] + A[i - 1];
        pSqSum[i] = pSqSum[i - 1] + A[i - 1] * A[i - 1];
    }
}

int minError(int lo, int hi)
{
    int sum = pSum[hi + 1] - pSum[lo];
    int sqSum = pSqSum[hi + 1] - pSqSum[lo];

    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int ret = sqSum - (2 * m * sum) + (m * m * (hi - lo + 1));

    return ret;
}

int quantize(int from, int parts)
{
    if (from == n)
    {
        return 0;
    }

    if (parts == 0)
    {
        return INF;
    }

    int& ret = cache[from][parts];
    if (ret != -1)
    {
        return ret;
    }

    ret = INF;

    for (int partSize = 1; from + partSize <= n; partSize++)
    {
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
    }

    return ret;
}
