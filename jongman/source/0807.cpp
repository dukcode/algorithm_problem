// 0807.cpp - 와일드 카드 문제를 해결하는 동적 계획법 알고리즘
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int cache[101][101];
string wildCard;
string fileName;

bool isMatch(int w, int f);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0807_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {

        cin >> wildCard;
        int n; cin >> n;

        for (int i = 0; i < n; i++)
        {
            memset(cache, -1, sizeof(cache));
            cin >> fileName;

            if (isMatch(0, 0))
            {
                cout << fileName << '\n';
            }
        }
    }

    return 0;
}

bool isMatch(int w, int f)
{
    int& ret = cache[w][f];

    if (ret != -1)
    {
        return ret;
    }

    while (w < wildCard.size() && f < fileName.size() && (wildCard[w] == '?' || wildCard[w] == fileName[f]))
    {
        w++;
        f++;
    }

    if (w == wildCard.size())
    {
        return ret = (f == fileName.size());
    }

    if (wildCard[w] == '*')
    {
        for (int skip = 0; f + skip <= fileName.size(); skip++)
        {
            if (isMatch(w + 1, f + skip))
            {
                return ret = 1;
            }
        }
    }

    return ret = 0;
}
