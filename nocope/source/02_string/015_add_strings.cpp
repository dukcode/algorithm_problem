// [leetcode 415] Add Strings
#include <string>
#include <algorithm>

std::string addStrings(std::string& num1, std::string& nums2)
{
    std::string res;

    const std::size_t m = num1.size();
    const std::size_t n = num2.size();

    int num1Idx = m - 1;
    int num2Idx = n - 1;

    int carry = 0;
    while (num1Idx >= 0 && num2Idx >= 0)
    {
        int sum = (num1[num1Idx] - '0') + (num2[num2Idx] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;

        num1Idx--;
        num2Idx--;
    }

    if (m > n)
    {
        while (num1Idx >= 0)
        {
            int sum = (num1[num1Idx] - '0') + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;

            num1Idx--;
        }
    }
    else if (m < n)
    {
        while (num2Idx >= 0)
        {
            int sum = (num2[num2Idx] - '0') + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;

            num2Idx--;
        }
    }

    if (carry != 0)
    {
        res.push_back(carry + '0');
    }

    std::reverse(res.begin(), res.end());
    return res;
}
