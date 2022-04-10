// 7579.cpp -- 앱
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int cache[100][1000000 + 1];

int n;
int toRemove;

int memory[100];
int cost[100];

int getLeastCoast(int app, int toRemove);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("7579_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n >> toRemove;

    for (int i = 0; i < n; ++i)
    {
        cin >> memory[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> cost[i];
    }

    cout << getLeastCoast(0, toRemove) << '\n';

    return 0;
}

int getLeastCoast(int app, int toRemove)
{

    if (app == n - 1)
    {
        if (toRemove > 0)
        {
            return INF;
        }
        return 0;
    }

    int& ret = cache[app][toRemove];
    if (ret != -1)
    {
        return ret;
    }

    ret = getLeastCoast(app + 1, toRemove);

    return ret = min(ret, getLeastCoast(app + 1, toRemove - memory[app]) + cost[app]);
}
