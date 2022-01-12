// 2579.cpp -- 계단 오르기
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int score[301];

int cache[301];

// stair 까지 밟았을 때 최대 점수 반환
int getMaxScore(int stair);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("2579_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    cout << getMaxScore(n - 1) << '\n';

    return 0;
}

int getMaxScore(int stair)
{
    int& ret = cache[stair];
    if (ret != -1)
    {
        return ret;
    }

    // base case 1
    if (stair == 1)
    {
        return ret = score[1] + score[0];
    }

    // base case 2
    if (stair == 0)
    {
        return ret = score[stair];
    }

    return ret = score[stair] + max(getMaxScore(stair - 2), getMaxScore(stair - 3) + score[stair - 1]);

}
