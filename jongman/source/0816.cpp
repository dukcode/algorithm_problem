// 0816.cpp -- 타일링의 수를 세는 동적 계획법 알고리즘

const int MOD = 1000000007;

int cache[101];

int tiling(int width)
{
    if (width <= 1)
    {
        return 1;
    }

    int& ret = cache[width];
    if (ret != -1)
    {
        return ret;
    }

    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;

}
