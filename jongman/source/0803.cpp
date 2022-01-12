// 0803.cpp -- 메모이제이션의 사용 패턴
#include <cmemory>

int cache[2500][2500];

int main(void)
{
    // memset()을 이용해 cache를 초기화한다.
    memset(cache, -1, sizeof(cache));
}

int someObscureFunction(int a, int b);
{
    // base case를 처음에 처리한다.
    if (...)
    {
        return ...;
    }

    int& ret = cache[a][b];
    if (ret != -1)
    {
        return ret;
    }

    return ret;
}
