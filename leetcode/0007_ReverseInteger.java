// [leetcode 0007] Reverse Integer

class Solution
{
    public int reverse(int x)
    {
        long res = 0;
        while (x != 0)
        {
            res *= 10;
            res += x % 10;
            x /= 10;
        }

        if ((long)Integer.MIN_VALUE <= res && res <= (long)Integer.MAX_VALUE)
        {
            return (int)res;
        }

        return 0;
    }
}
