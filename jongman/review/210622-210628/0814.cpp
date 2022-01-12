// 0814.cpp -- PI
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int cache[10000];

string str;

int judge(int start, int end);
int getMinLevel(int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0814_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> str;
        cout << str << " : " << getMinLevel(0) << '\n';
    }

    return 0;
}

int judge(int start, int end)
{
    string M = str.substr(start, end - start + 1);

    if (M == string(M.size(), M[0]))
    {
        return 1;
    }

    bool progressive = true;
    for (int i = 0; i < M.size() - 1; ++i)
    {
        if(M[i + 1] - M[i] != M[1] - M[0])
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

int getMinLevel(int start)
{
    // base case
    if (start == str.size())
    {
        return 0;
    }

    int& ret = cache[start];
    if (ret != -1)
    {
        return ret;
    }


    ret = INF;
    for (int length = 3; length <= 5; ++length)
    {
        if (start + length <= str.size())
        {
            ret = min(ret, getMinLevel(start + length) + judge(start, start + length - 1));
        }
    }

    return ret;
}
