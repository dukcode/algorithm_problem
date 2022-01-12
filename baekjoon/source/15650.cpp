// 15650.cpp -- N과 M (2)
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int m;

void print(const vector<int>& v);
void sequence(vector<int>& v);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("15650_input.txt", "r", stdin);

    cin >> n >> m;

    vector<int> v;
    sequence(v);

    return 0;
}

void print(const vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void sequence(vector<int>& v)
{
    // base case
    if (v.size() == m)
    {
        print(v);
    }

    int largest = v.empty() ? 1 : v.back() + 1;

    for (int next = largest; next <= n; ++next)
    {
        v.push_back(next);
        sequence(v);
        v.pop_back();
    }
}
