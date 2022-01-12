// 0802.cpp

int cache[30][30];

int bino(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }

    int& ret = cache[n][r];
    if (ret != -1)
    {
        return ret;
    }

    return ret = bino(n - 1, r) + bino(n - 1, r - 1);
}
