// 0602.cpp -- n개의 원소 중 m개를 고르는 모든 조합을 출력하는 함수
#include <iostream>
#include <vector>

using namespace std;

void pick(int n, vector<int> picked, int toPick);
void printPicked(const vector<int> picked);

int main(void)
{
    vector<int> picked;
    pick(4, picked, 2);

    return 0;
}

void pick(int n, vector<int> picked, int toPick)
{
    if (toPick == 0)
    {
        printPicked(picked);
        return;
    }

    int next = picked.empty() ? 0 : picked.back() + 1;

    for (int i = next; i < n; i++)
    {
        picked.push_back(i);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }

}

void printPicked(const vector<int> picked)
{
    int N = picked.size();
    for (int i = 0; i < N; i++)
    {
        cout << picked[i] << ' ';
    }
    cout << '\n';
}
