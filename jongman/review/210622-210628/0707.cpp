// 0707.cpp
#include <iostream>
#include <cstdio>
#include <vector>

int bureForce(const vector<int>& h)
{
    int ret = 0;
    
    for (int left = 0; left < h.size(); ++left)
    {
        int minHeight = h[left];
        for (int right = left; right < h.size(); ++right)
        {
            minHeight = min(minHeight, h[right]);

            ret = max(ret, (left - right + 1) * minHeight);
        }
    }

    return ret;
}
