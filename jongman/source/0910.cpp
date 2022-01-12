// 0910.cpp -- k번째 최대 증가 부분 수열
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000000000 + 1;

int n;
int k;
int S[500];

int cache[501];
int cacheCount[501];

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0910_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        memset(cacheCount, -1, sizeof(cacheCount));

        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> S[i];
        }

        vector<int> lis;
        reconstruct(-1, k, lis); 
        cout << lis.size() << '\n';
        for (int i = 0; i < lis.size(); ++i)
        {
            cout << lis[i] << ' ';
        }
        cout << '\n';

    }

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
        if (start == -1 || S[start] < S[next])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}

int count(int start)
{
    // base case
    if (lis(start) == 1)
    {
        return 1;
    }
    
    int& ret = cacheCount[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    for (int next = start + 1; next < n; ++next)
    {
        if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
        {
            ret = min<long long>(MAX, (long long)ret + count(next));
        }
    }

    return ret;
}

void reconstruct(int start, int skip, vector<int>& lis)
{
    // base case
    if (start != -1)
    {
        lis.push_back(S[start]);
    }

    vector< pair<int, int> > followers;
    for (int next = start + 1; next < n; ++next)
    {
        if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
        {
            followers.push_back(make_pair(S[next], next));
        }
    }

    sort(followers.begin(), followers.end());

    for (int i = 0; i < followers.size(); ++i)
    {
        int idx = followers[i].second;
        int cnt = count(idx);

        if (cnt <= skip)
        {
            skip -= cnt;
        }
        else
        {
            reconstruct(idx, skip, lis);
            break;
        }
    }
}
