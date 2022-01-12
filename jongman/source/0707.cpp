// 울타리 잘라내기 문제를 해결하는 O(n^2) 알고리즘
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxArea(vector<int>& h);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0707_input.txt", "r", stdin);

    int testCase; cin >> testCase;

    while (testCase--)
    {
        int N; cin >> N;
        vector<int> h;
        for (int i = 0; i < N; i++)
        {
            int height; cin >> height;
            h.push_back(height);
        }
        cout << getMaxArea(h) << '\n';
    }

    return 0;
}

int getMaxArea(vector<int>& h)
{
    int ret = 0;
    int size = h.size();
    for (int first = 0; first < size; first++)
    {
        int minHeight = h[first];
        for (int second = first; second < size; second++)
        {
            minHeight = min(minHeight, h[second]);

            ret = max(ret, minHeight * (second - first + 1));
        }
    }

    return ret;
}
