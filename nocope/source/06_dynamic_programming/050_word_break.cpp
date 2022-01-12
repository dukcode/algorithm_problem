// [leetcode 139] Word Break
#include <string>
#include <vector>
#include <unordered_set>

// hashSet 쓰는 방법론 + 앞에서 부터 bottom_up 방식 쓰는 방법
bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    std::unordered_set<std::string> wordSet;
    for (const std::string& word : wordDict)
    {
        wordSet.emplace(word);
    }

    const int n = s.size();
    std::vector<bool> cache(n + 1, false);
    cache[0] = true;

    // idx 처리 잘하기
    for (int idx = 1; idx <= n; ++idx)
    {
        for (const std::string& word : wordSet)
        {
            const int wordLength = word.size();
            const int prevIdx = idx - wordLength;

            if (prevIdx < 0)
            {
                continue;
            }

            if (cache[prevIdx] == false)
            {
                continue;
            }

            if (std::string(s.begin() + prevIdx, s.begin() + idx) == word)
            {
                cache[idx] = true;
                break;
            }
        }
    }

    return cache.back();
}
