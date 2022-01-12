// [leetcode 242] Valid Anagram
#include <string>
#include <unordered_map>
#include <utility>

bool isAnagram(std::string s, std::string t)
{
    const int l = s.size();
    const int n = t.size();

    if (l != n)
    {
        return false;
    }


    std::unordered_map<char, int> m;
    for (int i = 0; i < n; ++i)
    {
        m[s[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
        if (m.find(t[i]) == m.end())
        {
            return false;
        }
        else
        {
            m[t[i]]--;
        }
    }

    for (const pair<char, int> e : m)
    {
        if (e.second != 0)
        {
            return false;
        }
    }

    return true;
}
