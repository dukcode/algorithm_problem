// 0902.cpp -- PACKING
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int w;

string name[100];
int volume[100];
int need[100];

int cache[100][1001];

int pack(int item, int capacity);
void reconstruct(int item, int capacity, vector<string>& picked);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0902_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> n >> w;
        for (int i = 0; i < n; ++i)
        {
            cin >> name[i] >> volume[i] >> need[i];
        }

        cout << pack(0, w) << ' ';
        vector<string> picked;
        reconstruct(0, w, picked);
        cout << picked.size() << '\n';
        for (int i = 0; i < picked.size(); ++i)
        {
            cout << picked[i] << '\n';
        }
    }

    return 0;
}

int pack(int item, int capacity)
{
    // base case
    if (item == n)
    {
        return 0;
    }

    int& ret = cache[item][capacity];
    if (ret != -1)
    {
        return ret;
    }

    ret = pack(item + 1, capacity);
    if (capacity >= volume[item])
    {
        ret = max(ret, need[item] + pack(item + 1, capacity - volume[item]));
    }

    return ret;
}

void reconstruct(int item, int capacity, vector<string>& picked)
{
    if (item == n)
    {
        return;
    }

    if (pack(item, capacity) == pack(item + 1, capacity))
    {
        reconstruct(item + 1, capacity, picked);
    }
    else
    {
        picked.push_back(name[item]);
        reconstruct(item + 1, capacity - volume[item], picked);
    }
}
