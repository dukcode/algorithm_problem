// 0708.cpp -- 울타리 잘라내기 문제룰 해결하는 분할 정복 알고리즘
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int getMaxArea(vector<int>& h, int left, int right);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0708_input.txt", "r", stdin);

    int testCase; cin >> testCase;

    while (testCase--)
    {
        int N; cin >> N;
        int height; vector<int> h;
        for (int i = 0; i < N; i++)
        {
            cin >> height;
            h.push_back(height);
        }

        cout << getMaxArea(h, 0, N - 1) << '\n';
    }
    
    return 0;
}

int getMaxArea(vector<int>& h, int left, int right)
{
    // base case : left == right
    if (left == right)
    {
        return h[left];
    }

    int mid = (left + right) / 2;
    int ret = max(getMaxArea(h, left, mid), getMaxArea(h, mid + 1, right));

    int lo = mid; int hi = mid + 1;
    int minHeight = min(h[lo], h[hi]);

    while (left < lo || hi < right)
    {
        if (hi < right && (left == lo || h[lo - 1] < h[hi + 1]))
        {
            hi++;
            minHeight = min(minHeight, h[hi]);
        }
        else
        {
            lo--;
            minHeight = min(minHeight, h[lo]);
        }

        ret = max(ret, minHeight * (hi - lo + 1));
    }

    return ret;
}
