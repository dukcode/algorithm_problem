// [leetcode 64] Minimum Path Sum
#include <vector>

int minPathSum(std::vector<std::vector<int>>& grid)
{
    const int m = grid.size();
    const int n = grid[0].size();

    for (int i = 1; i < n; ++i)
    {
        grid[0][i] += grid[0][i - 1];
    }

    for (int y = 1; y < m; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            if (x == 0)
            {
                grid[y][x] += grid[y - 1][x];
                continue;
            }

            grid[y][x] += min(grid[y - 1][x], grid[y][x - 1]);
        }
    }

    return grid[m - 1][n - 1];
}
