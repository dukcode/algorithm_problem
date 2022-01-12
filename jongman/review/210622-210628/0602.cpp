// 0603.cpp -- n개의 원소중(0 부터) m개의 원소 출력
#include <vector>

int n;
int m;

void printPick(const vector<int>& picked)
{
    for (int i = 0; i < picked.size(); i++)
    {
        cout << picked[i] << ' ';
    }
    cout << '\n';
}

void pick(vector<int>& picked, int toPick)
{
    // base case
    if (toPick == 0)
    {
        printPick(picked);
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < n; ++next)
    {
        picked.push_back(next);
        pick(picked, toPick - 1);
        picked.pop_back();
    }
}
