// 0602.cpp -- n개의 원소 중 m고르는 모든 조합을 찾는 알고리즘
#include <iostream>
#include <vector>

using namespace std;

void pick(int n, vector<int>& picked, int toPick);
void printPicked(const vector<int>& picked);

int main(void)
{
    vector<int> picked;
    pick(10, picked, 5);

    return 0;
}

void pick(int n, vector<int>& picked, int toPick)
{
    if (toPick == 0)
    {
        printPicked(picked);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < n; next++)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

void printPicked(const vector<int>& picked)
{
    for (int i = 0; i < picked.size(); i++)
    {
        cout << picked[i] << ' ';
    }
    cout << endl;
}
