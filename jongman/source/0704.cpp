// 0703.cpp -- 두 큰 수를 곱하는 O(n^2) 알고리즘
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void normalize(vector<int>& num);
vector<int> multiply(const vector<int>& a, const vector<int>& b);

vector<int> karatsuba(vector<int>& a, vector<int>& b);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("", "r", stdin);

    return 0;
}

void normalize(vector<int>& num)
{
    num.push_back(0);
    for (int i = 0; i + 1 < num.size(); i++)
    {
        if (num[i] < 0)
        {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while (num.size() > 1 && num.back() == 0)
    {
        num.pop_back();
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    
    for (int i = 0; i <a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            c[i + j] = a[i] * b[j];
        }
    }
    normalize(c);
    
    return c;
}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
    int an = a.size(); int bn = b.size();

    // base case : a 또는 b가 비어있는 경우
    if (an == 0 || bn == 0)
    {
        return vector<int>();
    }

    // base case : a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다
    if (an < 50)
    {
        return multiply(a, b);
    }

    int half
}
