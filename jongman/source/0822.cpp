// 0822.cpp -- 두니아 박사의 탈옥 문제를 해결하는 완전 탐색 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;  // 마을의 수
int d;  // 지난 일수
int p;  // 교도소가 있는 마을의 번호
int connected[50][50];
int deg[50];

double search(vector<int>& path);

int main(void)
{
    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(connected, 0, sizeof(connected));
        memset(deg, 0, sizeof(deg));

        cin >> n >> d >> p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> connected[i][j];

                if (connected[i][j] == 1)
                {
                    deg[i]++;
                }
            }
        }

        int t; cin >> t;
        int temp;
        vector<int> q;

        for (int i = 0 i < t; i++)
        {
            cin >> temp;
            q.push_back(temp);

        }

    }

    return 0;
}

double search(vector<int>& path)
{
    // base case
    if (path.size() == d + 1)
    {
        if (path.back() != q)
        {
            return 0.0;
        }

        double ret = = 1.0;
        for (int i = 0; i < path.size() - 1; i++)
        {
            ret /= deg[path[i]];
        }
        
        return ret;
    }

    double ret = 0.0;
    for (int there = 0; there < n; there++)
    {
        if (connected[path.back()][there])
        {
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    }

    return ret;
}
