// 2565.cpp -- 전깃줄
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector< pair<int, int> > link;

int cache[101];

int lis(int start);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("2565_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    int first; int second;
    for (int i = 0; i < n; ++i)
    {
        cin >> first >> second;
        link.push_back(make_pair(first, second));
    }

    sort(link.begin(), link.end());

    cout << n - (lis(-1) - 1) << '\n';

    return 0;
}

int lis(int start)
{
    int& ret = cache[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (start == -1 || link[start].second < link[next].second)
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}
