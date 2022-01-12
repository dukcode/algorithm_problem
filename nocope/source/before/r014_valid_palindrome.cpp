#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool isPalindrome(string& str)
{
    const int n = str.size();

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        while (!isalnum(str[left]) && left < right)
        {
            left++;
        }

        while (!isalnum(str[right]) && left < right)
        {
            right--;
        }

        if (toupper(str[left]) != toupper(str[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main(void)
{

    return 0;
}
