// 0701.cpp

int fastSum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n % 2 == 1)
    {
        return n + fastSum(n - 1);
    }

    return fastSum(n / 2) * 2 + (n / 2) * (n / 2);
}
