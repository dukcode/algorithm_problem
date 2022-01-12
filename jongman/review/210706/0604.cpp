// 0604.cpp -- 소풍

bool taken[10];

bool areFriends[10][10];

int countPairings(void)
{
    // base case - 모두 친구가 된 경우 카운트
    // 첫번째 짝이 없는 친구를 찾는다
    int firstFree = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!taken[i])
        {
            firstFree = i;
            break;
        }
    }

    // 짝 없는 사람이 아무도 없는 경우 카운트
    if (firstFree == -1)
    {
        return 1;
    }

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
    {
        if (areFriends[pairWith][firstFree] && !taken[pairWith])
        {
            taken[pairWith] = taken[firstFree] = true;
            ret += countPairings();
            taken[pairWith] = taken[firstFree] = false;
        }
    }

    return ret;
}
