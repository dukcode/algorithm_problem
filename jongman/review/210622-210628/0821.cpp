// 0821.cpp -- POLY
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 10000000;

int cache[101][101];

int poly(int numFirstLine, int blockLeft);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0821_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));
    
    int testCase; cin >> testCase;
    while (testCase--)
    {
        int n; cin >> n;
        cout << poly(0, n) << '\n';
    }

    return 0;
}

int poly(int numFirstLine, int blockLeft)
{
    int& ret = cache[numFirstLine][blockLeft];
    if (ret != -1)
    {
        return ret;
    }

    // base case
    if (blockLeft == 0)
    {
        return ret = 1;
    }

    ret = 0;
    for (int numNextLine = 1; numNextLine <= blockLeft; ++numNextLine)
    {
        if (numFirstLine == 0)
        {
            ret = (ret + poly(numNextLine, blockLeft - numNextLine)) % MOD;
        }
        else
        {
            ret = (ret + (poly(numNextLine, blockLeft - numNextLine) * (numFirstLine + numNextLine - 1) % MOD)) % MOD;
        }
    }

    return ret;
}
