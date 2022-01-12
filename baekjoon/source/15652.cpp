// 15652.cpp -- N과 M (4)
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
    // freopen("15654_input.txt", "r", stdin);

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
        return;
    }

    int smallest = v.empty() ? 1 : v.back();

    for (int next = smallest; next <= n; ++next)
    {
        v.push_back(next);
        sequence(v);
        v.pop_back();
    }
}
