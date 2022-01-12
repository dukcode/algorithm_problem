// 0823.cpp -- 두니아 박사의 탈옥 문제를 해결하는 동적 계획법 알고리즘
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;  // 마을의 수
int d;  // 지난 일수
int p;  // 교도소가 있는 마을의 번호
int connected[50][50];
int deg[50];

double cache[50][100];

double search(int here, int days);

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

double search(int here, int days)
{
    // base case
    if (days == 0)
    {
        return here == p ? 1.0 : 0.0;
    }

    double& ret = cache[here][days];
    if (ret > -0.5)
    {
        return ret;
    }

    for (int there = 0; there < n; there++)
    {
        if (connected[here][there])
        {
            ret += search(there, days - 1) / deg[there];
        }
    }

    return ret;

}
