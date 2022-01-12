// 0601.cpp

int recursiveSum(int n)
{
    // base case
    if (1 == n)
    {
        return 1;
    }

    return recursiveSum(n - 1) + n;
}
