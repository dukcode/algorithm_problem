// [leetcode 125] Valid Parindrome
#include <string>
#include <cctype>

bool isPalindrome(std::string& s)
{
    std::size_t n = s.size();

    std::size_t left = 0;
    std::size_t right = n - 1;

    while (left < right)
    {
        if (left < n && !std::isalnum(s[left]))
        {
            left++;
            continue;
        }

        if (right >= 0 && !std::isalnum(s[right]))
        {
            right--;
            continue;
        }

        if (std::tolower(s[left]) == std::tolower(s[right]))
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}
