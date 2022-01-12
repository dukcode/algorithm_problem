#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

bool wordPattern(std::string pattern, std::string s)
    {
        std::vector<std::string> words;
        const int n = pattern.size();
    
        std::stringstream ss(s);
        std::string word;
        while (ss >> word)
        {
            words.emplace_back(word);
        }

        if (n != words.size())
        {
            return false;
        }
        
        std::unordered_map<char, std::string> pTow;
        for (int idx = 0; idx < n; ++idx)
        {
            if (pTow.find(pattern[idx]) != pTow.end())
            {
                if (pTow[pattern[idx]] != words[idx])
                {
                    return false;
                }
            }
            else
            {
                pTow.emplace(pattern[idx], words[idx]);
            }
        }
    
    
        std::unordered_map<std::string, char> wTop;
        for (int idx = 0; idx < n; ++idx)
        {
            if (wTop.find(words[idx]) != wTop.end())
            {
                if (wTop[words[idx]] != pattern[idx])
                {
                    return false;
                }
            }
            else
            {
                wTop.emplace(words[idx], pattern[idx]);
            }
        }
    
        return true;
    }

int main(void)
{
    wordPattern("asdaaaaaaaa", "qwe asd zxca");

    return 0;
}
