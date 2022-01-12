// [leetcode 387] First Unique Character in a String
#include <string>
#include <unordered_map>

int firstUniqueChar(std::string s)
{
    const int n = s.size();
    std::unordered_map<char, int> m;

    for (int i = 0; i < n; ++i)
    {
        m[s[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
        if (m[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}
