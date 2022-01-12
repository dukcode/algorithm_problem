#include <iostream>
#include <string>
#include <cctype>

bool isAlphabet(const char ch);
bool isPalindrome(const std::string& str);

int main(void)
{
    std::string str;
    std::getline(std::cin, str);

    std::cout << isPalindrome(str) << std::endl;

    return 0;
}

bool isAlphanumeric(const char ch)
{
    if ((65 <= ch && ch <= 90) || (97 <= ch && ch <= 122))
    {
        return true;
    }

    if (48 <= ch && ch <= 57)
    {
        return true;
    }

    return false;
}


bool isPalindrome(const std::string& str)
{
    int n = str.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        while (!isAlphanumeric(str[left]) && left < n)
        {
            left++;
        }

        while (!isAlphanumeric(str[right]) && right >= 0)
        {
            right--;
        }

        if (left == n || right == 0)
        {
            return true;
        }

        char leftChar = toupper(str[left]);
        char rightChar = toupper(str[right]);

        if (leftChar == rightChar)
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
