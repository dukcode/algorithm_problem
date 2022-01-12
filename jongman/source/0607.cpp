// 0607.cpp -- 여행하는 외판원 문제를 해결하는 재귀 호출 알고리즘
#include <cstdio>
#include <iostream>

using namespace std;

int n; // 도시의 수
double dist[MAX][MAX]; // 두 도시 간의 거리를 저장하는 배열

double shortestPath(vector<int>& path, vector<bool>& visited, double currentPath);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("", "r", stdin);

    return 0;
}

double shortestPath(vector<int>& path, vector<bool>& visited, double currentPath)
{
    // base case : 모든 도시를 방문했을 경우
    if (path.size() == n)
    {
        return currentPath + dist[path.back()][path[0]];
    }

    double ret = INF;

    for (int next = 0; next < n; next++)
    {
        if (visited[next])
        {
            continue;
        }

        path.push_back(next);
        visited[next] = true;
        
        double candidate = shortestPath(path, visited, currentPath + dist[path.back()][next]);
        ret = min(ret, candidate);

        path.pop_back();
        visited[next] = false;
    }

    return ret;
}
