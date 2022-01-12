// [leetcode 205] Isomorphic Strings
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t)
{
    const int n = s.size();

    // sTot, tTos 2개 해야함
    std::unordered_map<char, char> sTot;
    std::unordered_map<char, char> tTos;
    for (int i = 0; i < n; ++i)
    {
        if (sTot.find(s[i]) == sTot.end())
        {
            sTot.emplace(s[i], t[i]);
        }
        else if (sTot[s[i]] != t[i])
        {
            return false;
        }

        if (tTos.find(t[i]) == tTos.end())
        {
            tTos.emplace(t[i], s[i]);
        }
        else if (tTos[t[i]] != s[i])
        {
            return false;
        }
    }

    return true;
}
