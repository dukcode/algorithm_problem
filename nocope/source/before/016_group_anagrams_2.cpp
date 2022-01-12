#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

array<int, 26> countingArr;

struct ArrIntHash
{
    std::size_t operator()(array<int, 26> const& a) const
    {
        hash<int> hasher;
        size_t result = 0;
        for (size_t i = 0; i < 26; i++)
        {
            result = result * 31 + hasher(a[i]);
        }

        return result;
    }
};

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<array<int, 26>, vector<string>, ArrIntHash> map;
    vector<vector<string>> res;

    int idx = 0;
    for (string& s : strs)
    {
        countingArr.fill(0);
        for (int i = 0; i < s.size(); i++)
        {
            countingArr[s[i] - 'a']++;
        }
        map[countingArr].emplace_back(strs[idx]);
        ++idx;
    }
    
    for (auto& m : map)
    {
        res.emplace_back(m.second);
    }
    
    return res;
}
int main(void)
{

    return 0;
}
