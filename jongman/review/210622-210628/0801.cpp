// 0801.cpp

int bino(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }

    return bino(n - 1, r) + bino(n - 1, r - 1);
}
