// 0902.cpp -- 여행 짐 싸기 (문제ID : PACKING, 난이도 중)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int cache[1001][100];

int n; // 물건의 수 (1 <= n <= 100)
int w; // 캐리어 용량 (1 <= w <= 1000)

string name[100];
int volume[100];
int necessity[100];

int choiceItem(int capacity, int item);
void reconstruct(int capacity, int item, vector<string>& picked);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0902_input.txt", "r", stdin);

    // (1 <= testCase <= 50)
    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> n >> w;
        for (int i = 0; i < n; i++)
        {
            cin >> name[i] >> volume[i] >> necessity[i];
        }

        vector<string> picked;
        reconstruct(w, 0, picked);

        cout << choiceItem(w, 0) << ' ' << picked.size() << '\n';
        for (int i = 0; i < picked.size(); i++)
        {
            cout << picked[i] << '\n';
        }
    }

    return 0;
}

int choiceItem(int capacity, int item)
{
    int& ret = cache[capacity][item];
    if (ret != -1)
    {
        return ret;
    }

    if (item == n)
    {
        return 0;
    }

    ret = choiceItem(capacity, item + 1);
    if (capacity >= volume[item])
    {
        ret = max(ret, choiceItem(capacity - volume[item], item + 1) + necessity[item]);
    }

    return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked)
{
    if (item == n)
    {
        return;
    }

    if (choiceItem(capacity, item) == choiceItem(capacity, item + 1))
    {
        reconstruct(capacity, item + 1, picked);
    }
    else
    {
        picked.push_back(name[item]);
        reconstruct(capacity - volume[item], item + 1, picked);
    }
}
