// 0818_1.cpp -- SNAIL
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n;  // depth
int m;  // days

double cache[MAX_N + 1][MAX_M * 2 + 1];

double climb(int day, int distance);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0818_1_input.txt", "r", stdin);

    cout << fixed;
    cout.setf(ios_base::showpoint);
    cout.precision(10);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(cache, -2.0, sizeof(cache));
        cin >> n >> m;
        cout << climb(0, 0) << '\n';
    }


    return 0;
}

double climb(int day, int distance)
{
    // base case
    if (day == m)
    {
        return distance >= n ? 1.0 : 0.0;
    }

    double& ret = cache[day][distance];
    if (ret > -1.0)
    {
        return ret;
    }

    return ret = 0.25 * climb(day + 1, distance + 1) + 0.75 * climb(day + 1, distance + 2);
}
