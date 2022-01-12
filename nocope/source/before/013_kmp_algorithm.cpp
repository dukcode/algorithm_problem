#include <iostream>
#include <string>
#include <vector>

std::vector<int> kmp(const std::string& str, const std::string& subStr);
const std::vector<int> getPi(const std::string& str);


int main(void)
{
    std::string str;
    std::string subStr;

    std::getline(std::cin, str);
    std::getline(std::cin, subStr);

    std::vector<int> ans = kmp(str, subStr);

    std::cout << ans.size() << std::endl;
    for (const auto& e : ans)
    {
        std::cout << e << std::endl;
    }

    return 0;
}

const std::vector<int> getPi(const std::string& str)
{
    const int n = str.length();
    std::vector<int> pi(n, 0);

    int j = 0;
    for (int i = 1; i < n; i++)
    {
        while (str[i] != str[j] && j > 0)
        {
            j = pi[j - 1];
        }

        if (str[i] == str[j])
        {
            pi[i] = ++j;
        }
    }

    return pi;
}

std::vector<int> kmp(const std::string& str, const std::string& subStr)
{
    std::vector<int> pi = getPi(subStr);
    std::vector<int> ret{};

    int n = str.size();
    int m = subStr.size();

    int subIdx = 0;
    for (int idx = 0; idx < n; ++idx)
    {
        while (str[idx] != subStr[subIdx] && subIdx > 0)
        {
            subIdx = pi[subIdx - 1];
        }

        if (str[idx] == subStr[subIdx])
        {
            if (subIdx == m - 1)
            {
                ret.emplace_back(idx - m + 1);
                subIdx = pi[subIdx];
            }
            else
            {
                subIdx++;
            }
        }
    }

    return ret;
}
