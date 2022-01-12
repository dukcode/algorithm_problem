// 0605.cpp
#include <algorithm>

int n;

bool areFriend[10][10];
bool isTaken[10];

int countPairing(bool isTaken[10])
{
    bool firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (!isTaken[i])
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
    for (int toPair = firstFree + 1; toPair < n; ++toPair)
    {
        if (areFriend[firstFree][toPair] && !isTaken[toPair])
        {
            isTaken[firstFree] = isTaken[toPair] = true;
            ret += countPairing(isTaken));
            isTaken[firstFree] = isTaken[toPair] = false;
        }
    }

    return ret;
}
