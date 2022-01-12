// 0814.cpp -- 원주율 외우기 문제를 해결하는 동적 계획법 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int INF = 987654321;

string N;
int cache[10000];

int classify(int a, int b);
int memorize(int begin);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0814_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        N.clear();
        cin >> N;

        cout << memorize(0) << '\n';
    }

    return 0;
}

int classify(int a, int b)
{
    string M = N.substr(a, b - a + 1);

    if (M == string(M.size(), M[0]))
    {
        return 1;
    }

    bool progressive = true;
    for (int i = 0; i < M.size() - 1; i++)
    {
        if (M[i + 1] - M[i] != M[1] - M[0])
        {
            progressive = false;
        }
    }

    if (progressive && abs(M[1] - M[0]) == 1)
    {
        return 2;
    }

    bool alternating = true;
    for (int i = 0; i < M.size(); i++)
    {
        if (M[i] != M[i % 2])
        {
            alternating = false;
        }
    }

    if (alternating)
    {
        return 4;
    }

    if (progressive)
    {
        return 5;
    }

    return 10;
}

int memorize(int begin)
{
    // base case
    if (begin >= N.size())
    {
        return 0;
    }

    int& ret = cache[begin];
    if (ret != -1)
    {
        return ret;
    }

    ret = INF;
    for (int L = 3; L <= 5; L++)
    {
        ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
    }

    return ret;
}
