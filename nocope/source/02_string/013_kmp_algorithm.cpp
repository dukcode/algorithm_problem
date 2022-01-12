// [baekhoon 1786] 찾기
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

std::vector<int> getPi(const std::string& s)
{
    const std::size_t n = s.size();
    std::vector<int> pi(n, 0);

    std::size_t j = 0;
    for (std::size_t i = 1; i < n; ++i)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == s[j])
        {
            pi[i] = ++j;
        }
    }

    return pi;
}

std::vector<int> kmp(const std::string& s, const std::string& p)
{
    std::vector<int> res;
    const std::vector<int> pi = getPi(p);
    const std::size_t m = s.size();
    const std::size_t n = p.size();

    std::size_t j = 0;
    for (std::size_t i = 0; i < m; ++i)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == p[j])
        {
            if (j == n - 1)
            {
                res.emplace_back(i - n + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }

    return res;
}

int main(void)
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    // std::freopen("13_kmp_algorithm_input.txt", "r", stdin);

    std::string s;
    std::string p;

    std::getline(std::cin, s);
    std::getline(std::cin, p);
    
    std::vector<int> ans = kmp(s, p);
    const int n = ans.size();

    std::cout << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        std::cout << ans[i] + 1 << '\n';
    }

    return 0;
}
