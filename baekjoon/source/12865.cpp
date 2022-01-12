// 12865.cpp -- 평범한 배낭
#include <cstdio>
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

const int NEGINF = numeric_limits<int>::min();

int cache[100][100001];

int numItem;
int capacity;
int weight[100];
int value[100];

int getMaxValue(int item, int totalWeight);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("12865_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> numItem >> capacity;
    for (int i = 0; i < numItem; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    cout << getMaxValue(0, capacity) << '\n';

    return 0;
}

int getMaxValue(int item, int capacity)
{
    if (capacity < 0)
    {
        return NEGINF;
    }

    if (item == numItem)
    {
        return 0;
    }

    int& ret = cache[item][capacity];
    if (ret != -1)
    {
        return ret;
    }

    ret = getMaxValue(item + 1, capacity);
    return ret = max(ret, value[item] + getMaxValue(item + 1, capacity -  weight[item]));
}
