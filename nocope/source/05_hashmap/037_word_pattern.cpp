#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

bool wordPattern(std::string pattern, std::string s)
{
    const int n = pattern.size();
    std::stringstream ss(s);    // 사용법 익히기

    std::vector<std::string> words;
    std::string word;
    while (ss >> word)
    {
        words.emplace_back(word);
    }

    // 양방향
    std::unordered_map<char, std::string> pTow;
    for (int i = 0; i < n; ++i)
    {
        if (pTow.find(pattern[i]) == pTow.end())
        {
            pTow.emplace(pattern[i], words[i]);
        }
        else
        {
            if (pTow[pattern[i]] != words[i])
            {
                return false;
            }
        }
    }

    // 양방향
    std::unordered_map<std::string, char> wTop;
    for (int i = 0; i < n; ++i)
    {
        if (wTop.find(words[i]) == wTop.end())
        {
            wTop.emplace(words[i], pattern[i]);
        }
        else
        {
            if (wTop[words[i]] != pattern[i])
            {
                return false;
            }
        }
    }

    return true;
}
