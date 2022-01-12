#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t)
{
    const int n = s.size();
    const int m = t.size();
    if (n != m)
    {
        return false;
    }

    std::unordered_map<char, char> sTot;
    std::unordered_map<char, char> tTos;
    for (int i = 0; i < n; ++i)
    {
        if (sTot.find(s[i]) != sTot.end())
        {
            if (sTot[s[i]] != t
            {
                return false;
            }
        }
        else
        {
            sTot.emplace(s[i], t[i]);
        }

        if (tTos.find(t[i]) != tTos.end())
        {
            if (tTos[t[i]] != s[i])
            {
                return false;
            }
        }
        else
        {
            tTos.emplace(t[i], s[i]);
        }
    }

    return true;
}
