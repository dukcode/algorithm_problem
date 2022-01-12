// 0803.cpp -- WILDCARD
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string wildCard;
string fileName;

int cache[100][100];

int isMatched(int w, int f);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0803_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> wildCard;
        int n; cin >> n;
        while (n--)
        {
            memset(cache, -1, sizeof(cache));
            cin >> fileName;
            if (isMatched(0, 0))
            {
                cout << fileName << '\n';
            }
        }
    }

    return 0;
}

int isMatched(int w, int f)
{
    int& ret = cache[w][f];

    if (ret != -1)
    {
        return ret;
    }

    if(w < wildCard.size() && f < fileName.size() && (wildCard[w] == fileName[f] || wildCard[w] == '?'))
    {
        return ret = isMatched(w + 1, f + 1);
    }

    if (w == wildCard.size())
    {
        return ret = (f == fileName.size());
    }

    if (wildCard[w] == '*')
    {
        if(isMatched(w + 1, f) || (f < fileName.size() && isMatched(w, f + 1)))
        {
            return ret = 1;
        }
    }

    return ret = 0;
}
