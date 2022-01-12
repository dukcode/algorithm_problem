#include <string>
#include <unordered_map>

int firstUniqChar(string s)
{
    const auto n = s.size();
    int res = -1;
    std::unordered_map<char, int> m;

    for (std::size_t idx = 0; idx < n; ++idx)
    {
        if (m.find(s[idx]) != m.end())
        {
            m[s[idx]]++;
        }
        else
        {
            m.emplace(s[idx], 1);
        }
    }

    for (std::size_t idx = 0; idx < n; ++idx)
    {
        if (m[s[idx]] == 1)
        {
            res = idx;
            break;
        }
    }

    return res;
}
