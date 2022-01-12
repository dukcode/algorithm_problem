// [leetcode 0009] Palindrome Number

class Solution
{
    public boolean isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        
        String num = new String(Integer.toString(x));
        int length = num.length();
        int half = length / 2;
        for (int i = 0; i <= half; ++i)
        {
            if (num.charAt(i) != num.charAt(length - 1 - i))
            {
                return false;
            }
        }

        return true;
    }
}
