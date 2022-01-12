// 0818.cpp -- 우물을 기어오르는 달팽이
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("_input.txt", "r", stdin);

    return 0;
}

int climb(int day, int distance)
{
    // base case
    if (days == m)
    {
        return distance >= n ? 1 : 0;
    }

    int& ret = cache[day][distance];
    if (ret != -1)
    {
        return ret;
    }

    return ret = climb(day + 1, distance + 1), climb(day + 1, distance + 2);
}
