#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> map;
    vector<vector<string>> res;

    int idx = 0;
    for (string s : strs)
    {
        sort(s.begin(), s.end());
        map[s].emplace_back(strs[idx]);
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
