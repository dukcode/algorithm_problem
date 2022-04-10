// 1912.cpp -- 연속합
#include <cstdio>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

const int NEGINF = numeric_limits<int>::min();

int n;
int A[100000];

int cache[100000];

int getMaxContinuousSum(void);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("1912_input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << getMaxContinuousSum() << '\n';

    return 0;
}

int getMaxContinuousSum(void)
{
    cache[0] = A[0];

    int maxValue = cache[0];
    for (int i = 1; i < n; i++)
    {
        cache[i] = max(A[i], cache[i - 1] + A[i]);
        maxValue = max(maxValue, cache[i]);
    }

    return maxValue;
}


