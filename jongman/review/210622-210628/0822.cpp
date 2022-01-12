// 0822.cpp -- NUMB3RS_완전탐색
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

int deg[50];

double search(vector<int>& path);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0822_input.txt", "r", stdin);

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
            cin >> q;

            vector<int> path(1, p);
            cout << search(path) << ' ';
        }
        cout << '\n';
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

        double ret = 1.0;
        for (int i = 0; i + 1 < path.size(); ++i)
        {
            ret /= deg[path[i]];
        }
        return ret;
    }

    double ret = 0;
    for (int there = 0; there < n; ++there)
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
