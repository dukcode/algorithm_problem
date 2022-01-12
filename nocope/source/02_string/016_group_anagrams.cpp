// [leetcode 49] Group Anagrams
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrmas(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> map;
    
    int idx = 0;
    for (std::string s : strs)
    {
        std::sort(s.begin(), s.end());
        map[s].emplace_back(strs[idx]);
        idx++;
    }

    std::vector<std::vector<std::string>> res;
    for (auto& m : map)
    {
        res.emplace_back(m.second);
    }

    return res;
}
