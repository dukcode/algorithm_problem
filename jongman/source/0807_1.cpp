#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int cache[101][101];
string wildCard; string fileName;

int match(int w, int f);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0807_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> wildCard;

        int n; cin >> n;
        while (n--)
        {
            memset(cache, -1, sizeof(cache));
            cin >> fileName;

            if (match(0 , 0))
            {
                cout << fileName << '\n';
            }
        }
    }

    return 0;
}

int match(int w, int f)
{
    int& ret = cache[w][f];
    if (ret != -1)
    {
        return ret;
    }

    if (w < wildCard.size() && f < fileName.size() && (wildCard[w] == '?' || (wildCard[w] == fileName[f])))
    {
        return ret = match(w + 1, f + 1);
    }

    if (w == wildCard.size())
    {
        return ret = (f == fileName.size());
    }

    if (wildCard[w] == '*')
    {
            if (match(w + 1, f) || (f < fileName.size() && match(w, f + 1)))
            {
                return ret = 1;
            }
    }

    return ret = 0;
}
