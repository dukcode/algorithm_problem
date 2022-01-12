// 0604.cpp -- 소풍 문제를 해결하는 잘못된 재귀 호출 코드
#include <iostream>

using namespace std;

int countPairings(int n, bool taken[], bool areFriends[][10]);

int main(void)
{
    int C; cin >> C;
    while (C--)
    {
        int n; cin >> n;
        int m; cin >> m;

        bool taken[10];
        bool areFriends[10][10];
        for (int i = 0; i < 10; i++)
        {
            taken[i] = false;
            for (int j = 0; j < 10; j++)
            {
                areFriends[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int first; int second;
            cin >> first >> second;
            areFriends[first][second] = areFriends[second][first] = true;

        }
        cout << countPairings(n, taken, areFriends) << endl;
    }

    return 0;
}

int countPairings(int n, bool taken[], bool areFriends[][10])
{
    // base case
    int firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1)
    {
        return 1;
    }

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
    {
        if (!taken[pairWith] && areFriends[pairWith][firstFree])
        {
            taken[pairWith] = taken[firstFree] = true;
            ret += countPairings(n, taken, areFriends);
            taken[pairWith] = taken[firstFree] = false;
        }
    }
    return ret;
}
