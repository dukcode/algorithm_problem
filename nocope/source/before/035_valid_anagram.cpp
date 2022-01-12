#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t)
{
    const int n = s.size();
    const int m = t.size();

    if (n != m)
    {
        return false;
    }

    std::unordered_map<char, int> countingHashMap;
    for (int idx = 0; idx < n; ++idx)
    {
        if (countingHashMap.find(s[idx]) != countingHashMap.end())
        {
            countingHashMap[s[idx]]++;
        }
        else
        {
            countingHashMap.emplace(s[idx], 1);
        }
    }

    for (int idx = 0; idx < n; ++idx)
    {
        if (countingHashMap.find(t[idx]) != countingHashMap.end())
        {
            countingHashMap[t[idx]]--;
        }
        else
        {
            return false;
        }
    }

    for (const std::pair<char, int>& element : countingHashMap)
    {
        if (element.second != 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    std::cout << isAnagram("hello", "olleh") << '\n';
    std::cout << isAnagram("hello", "ooleh") << '\n';

    return 0;
}
