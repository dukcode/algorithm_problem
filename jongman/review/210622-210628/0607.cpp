// 0607.cpp

int n; // 도시의 수
double dist[MAX][MAX]; // 두 도시 간의 거리를 저장 하는 배열

double shortestPath(vector<bool>& visited, vector<int>& path, double currentLength)
{
    // base case
    if (path.size() == n)
    {
        return currentLength + dist[path.back()][path[0]];
    }

    double ret = INF;

    for (int next = 0; next < n; ++ next)
    {
        if(visited[next])
        {
            continue;
        }

        int here = path.back();

        path.push_back(next);
        visited[next] = true;

        ret = min(ret, shortestPath(visited, path, currentLength + dist[here][next]));

        visited[next] = false;
        path.pop_back();
    }

    return ret;
}
