#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

    string addStrings(string num1, string num2)
    {
        int n = num1.size();
        int m = num2.size();
    
        int first = n - 1; 
        int second = m - 1;
    
        string ret;
    
        int carry = 0;
        while (first >= 0 && second >= 0)
        {
            int num = int(num1[first] - '0') + int(num2[second] - '0') + carry;
            carry = num / 10;
            num = num % 10;
            ret.push_back(char(num + '0'));
    
            first--;
            second--;
        }
    
        if (first < 0 && second >= 0)
        {
            while (second >= 0)
            {
                int num = int(num2[second] - '0') + carry;
                carry = num / 10;
                num = num % 10;
                ret.push_back(char(num + '0'));
                
                second--;
            }
        }
    
        if (first >= 0 && second < 0)
        {
            while (first >= 0)
            {
                int num = int(num1[first] - '0') + carry;
                carry = num / 10;
                num = num % 10;
                ret.push_back(char(num + '0'));
                
                first--;
            }
        }
    
        if (carry != 0)
        {
            ret.push_back(char(carry + '0'));
        }
    
        reverse(ret.begin(), ret.end());
        return ret;
    }

int main(void)
{
    string num1;
    string num2;

    cin >> num1 >> num2;

    cout << addStrings(num1, num2) << endl;

    return 0;
}
