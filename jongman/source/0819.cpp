// 0819.cpp -- 비대칭 타일링 문제를 해결하는 동적 계획 알고리즘

int cache[101];

int tiling(int width)
{
    int& ret = cache[width];
    if (ret != -1)
    {
        return ret;
    }

    if (width <= 1)
    {
        return ret = 1;
    }

    return ret = tiling(n  - 1) + tiling(n - 2);
}

int asymmetric(int width)
{
    if (width % 2 == 1)
    {
        return tiling(width) - tiling(width / 2);
    }

    int ret = tiling(width);

    ret = (ret - tiling(width / 2) + MOD) % MOD;
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
    
    return ret;
}
