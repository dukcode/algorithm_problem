#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

vector<int> getPi(const string& subStr)
{
    const int n = subStr.size();
    vector<int> pi(n, 0);

    int j = 0;
    for (int i = 1; i < n; ++i)
    {
        while (subStr[j] != subStr[i] && j > 0)
        {
            j = pi[j - 1];
        }

        if (subStr[j] == subStr[i])
        {
            pi[i] = ++j;
        }
    }

    return pi;
}

vector<int> kmp(const string& str, const string& subStr)
{
    const vector<int> pi = getPi(subStr);
    std::vector<int> res;

    int n = str.size();
    int m = subStr.size();

    int subIdx = 0;
    for (int idx = 0; idx < n; ++idx)
    {
        while(str[idx] != subStr[subIdx] && subIdx > 0)
        {
            subIdx = pi[subIdx - 1];
        }

        if (str[idx] == subStr[subIdx])
        {
            if (subIdx == m - 1)
            {
                res.emplace_back(idx - (m - 1) + 1);
                subIdx = pi[subIdx];
            }
            else
            {
                subIdx++;
            }
        }
    }

    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("r013_kmp_algorithm_input.txt", "r", stdin);

    string t;
    string p;

    getline(cin, t);
    getline(cin, p);
    cout << t << '\n' << p << '\n';

    vector<int> res = kmp(t, p);

    cout << res.size() << '\n';
    for (const int e : res)
    {
        cout << e << ' ';
    }
    cout << '\n';

    return 0;
}
