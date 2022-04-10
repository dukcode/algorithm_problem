// 14501.cpp -- 퇴사(부르트포스)
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<int>& T, vector<int>& P, int day);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("14501_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        int N; cin >> N;
        vector<int> T(N); vector<int> P(N);
        for (int i = 0; i < N; i++)
        {
            cin >> T[i] >> P[i];
        }

        cout << solution(N, T, P, 0) << endl;
    }

    return 0;
}

int solution(int N, vector<int>& T, vector<int>& P, int day)
{
    // base case : 해당 day가 N이거나 (전에 한 상담이 딱 떨어짐), T 상담을 진행했을 때 day가 N을 넘을 때
    if (day == N)
    {
        return 0;
    }

    if (day + T[day] > N)
    {
        return 0;
    }

    int ret = 0;
    for (int i = day; i < N; i++)
    {
        if (i + T[i] > N)
        {
            continue;
        }

        ret = max(ret, solution(N, T, P, day + T[i]) + P[i]);
    }

    return ret;
}
