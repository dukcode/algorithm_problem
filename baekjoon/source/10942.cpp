// 10942.cpp -- 펠린드롬
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
int s;
int e;

int A[2001];

int cache[2001][2001];

bool solve(int s, int e);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("10942_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> s >> e;
        cout << solve(s, e) << '\n';
    }

    return 0;
}

bool solve(int s, int e)
{
    int& ret = cache[s][e];
    if (ret != -1)
    {
        return ret;
    }

    // base case 2
    if (s == e)
    {
        return ret = true;
    }

    // base case 3
    if (s + 1 == e)
    {
        return ret = (A[s] == A[e]);
    }


    if (A[s] == A[e])
    {
        return ret = solve(s + 1, e - 1);
    }

    return ret = false;
}
