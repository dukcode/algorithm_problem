// 15649_1.cpp -- N과 M(1)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
int m;

void print(const vector<int>& v);
void sequence(vector<int>& v);

bool taken[9];

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("15469_input.txt", "r", stdin);

    memset(taken, false, sizeof(taken));
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
        if (!taken[next])
        {
            taken[next] = true;
            v.push_back(next);
            sequence(v);
            taken[next] = false;
            v.pop_back();
        }
    }
}
