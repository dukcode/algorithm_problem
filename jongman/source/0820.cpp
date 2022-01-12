
// 0820.cpp -- 직접 비대칭 타일링의 수를 세는 동적 계획법 알고리즘

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

int asymmetric2(int width)
{
    if (width  <= 2)
    {
        return 0;
    }

    int ret = asymmetric2(width - 2) % MOD;
    ret = (ret + asymmetric2(width - 4) + MOD) % MOD;
    ret = (ret + tiling(width - 3) + MOD) % MOD;
    ret = (ret + tiling(width - 3) + MOD) % MOD;
    
    return ret;
}
