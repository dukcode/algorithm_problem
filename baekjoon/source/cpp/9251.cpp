// 9251.cpp -- LCS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int cache[1001][1001];

string str1;
string str2;

int lcs(int a, int b);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("9251_input.txt", "r", stdin);

    cin >> str1 >> str2;
    
    memset(cache, -1, sizeof(cache));

    cout << lcs(str1.length() - 1, str2.length() - 1) << '\n';

    return 0;
}

int lcs(int a, int b)
{
    if (a == -1 || b == -1)
    {
        return 0;
    }

    int& ret = cache[a][b];
    if (ret != -1)
    {
        return ret;
    }

    if (str2[b] == str1[a])
    {
        return ret = lcs(a - 1, b - 1) + 1;
    }

    return ret = lcs(a - 1, b) > lcs(a, b - 1) ? lcs(a - 1, b) : lcs(a, b - 1);
}
