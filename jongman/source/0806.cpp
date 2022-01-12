// 0806.cpp -- 와일드카드 문제를 해결하는 완전탐색 알고리즘
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool isMatch(const string& wildCard, const string& fileName);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("0806_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        string wildCard; cin >> wildCard;
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            string fileName; cin >> fileName;
            if (isMatch(wildCard, fileName))
            {
                cout << fileName << '\n';
            }
        }
    }
    return 0;
}

bool isMatch(const string& wildCard, const string& fileName)
{
    int pos = 0;

    // 문자열이 같은경우 또는 와일드카드의 문자열이 ?인 경우 넘긴다.
    while (pos < wildCard.size() && pos < fileName.size() && (wildCard[pos] == fileName[pos] || wildCard[pos] == '?'))
    {
        pos++;
    }

    // 넘겼을 때, pos가 문자열의 끝 ('\0')에 도달하면 true를 return
    if (pos == wildCard.size())
    {
        return pos == fileName.size();
    }

    if (wildCard[pos] == '*')
    {
        for (int skip = 0; skip + pos <= fileName.size(); skip++)
        {
            if (isMatch(wildCard.substr(pos + 1), fileName.substr(pos + skip)))
            {
                return true;
            }
        }
    }

    return false;
}
