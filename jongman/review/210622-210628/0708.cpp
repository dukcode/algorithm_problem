// 0708.cpp
#include <vector>

vector<int> h;

int getMaxSquareSize(int left, int right)
{
    if (left == right)
    {
        return h[left];
    }

    int ret = 0;
    int half = (left + right) / 2;

    ret = max(getMaxSquareSize(left, half), getMaxSquareSize(half + 1, right));

    int lo = half;
    int hi = half + 1;
    int height = min(h[lo], h[hi]);

    ret = max(ret, 2 * height);

    while (left < lo || hi < right)
    {
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
        {
            ++hi;
            height = min(height, h[hi]);
        }
        else
        {
            ++lo;
            height = min(height, h[lo]);
        }
    
        ret = max(ret, (hi - lo + 1) * height);
    }

    return ret;
}
