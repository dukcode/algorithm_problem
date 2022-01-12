// 0823.cpp -- NUMB3RS_완전탐색
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;          // 마을의 수 (2 <= n <= 50)
int d;          // 탈출 후 지금까지 지난 일 수 (1 <= d <= 100)
int p;          // 교도소가 있는 마을의 번호 (0 <= p < n)
bool connected[50][50];  // 길의 존재 여부  
int t;          // 계산할 마을의 수 (1 <= t <= n)
int q;          // 확률을 계산 할 마을의 번호 (1 <= q < n)

double cache[50][101];
int deg[50];

double search(int here, int days);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0824_input.txt", "r", stdin);

    cout << fixed;
    cout.setf(ios_base::showpoint);
    cout.precision(8);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(connected, false, sizeof(connected));
        memset(deg, 0, sizeof(deg));

        cin >> n >> d >> p;
        int temp;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                cin >> temp;
                connected[y][x] = temp;
                deg[y] += temp;
            }
        }

        cin >> t;
        for (int i = 0; i < t; ++i)
        {
            memset(cache, -1.0, sizeof(cache));
            cin >> q;

            cout << search(q, d) << ' ';
        }
        cout << '\n';
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

    ret = 0.0;
    for (int from = 0; from < n; ++from)
    {
        if (connected[from][here])
        {
            ret += search(from, days - 1) / deg[from];
        }
    }

    return ret;
}
