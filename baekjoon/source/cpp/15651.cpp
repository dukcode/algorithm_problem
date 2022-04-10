// 15651.cpp -- N과 M (3)
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
    // freopen("15651_input.txt", "r", stdin);

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


    for (int next = 1; next <= n; ++next)
    {
        v.emplace_back(next);
        sequence(v);
        v.pop_back();
    }
}
