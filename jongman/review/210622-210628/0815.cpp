// 0815.cpp -- QUANTIZE
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 987654321;

int n; // 숫자의 갯수
int s; // 사용 할 숫자

int A[100];

int pSum[100];
int pSqSum[100];

int cache[100][10];

void preCalc(void);
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
        memset(cache, -1, sizeof(cache));
        memset(pSum, 0, sizeof(pSum));
        memset(pSqSum, 0, sizeof(pSqSum));
        memset(A, 0, sizeof(A));

        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        
        preCalc();
        cout << quantize(0, s) << '\n';
    }

    return 0;
}

void preCalc(void)
{
    sort(A, A + n);

    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];

    for (int i = 1; i < n; i++)
    {
        pSum[i] = pSum[i - 1] + A[i];
        pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
    }
}

int minError(int lo, int hi)
{
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 :pSqSum[lo - 1]);

    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int ret = sqSum - 2 * m * sum + (hi - lo + 1) * m * m;

    return ret;
}

int quantize(int from, int parts)
{
    // base case
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
    for (int partSize = 1; from + partSize <= n; ++partSize)
    {
        ret = min(ret, quantize(from + partSize, parts - 1) + minError(from, from + partSize - 1));
    }

    return ret;
}
