// 0602.cpp -- n개의 원소 중 m개를 고르는 모든 조합을 출력하는 알고리즘
#include <iostream>
#include <vector>


void pick(vector<int>& picked, int toPick)
{
    if (toPick == 0)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << picked[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < n; ++next)
    {
        picked.push_back(next);
        pick(picked, toPick - 1);
        picked.pop_back();
    }
}
