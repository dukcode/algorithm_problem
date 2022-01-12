// [leetcode 48] Rotate Image
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix)
{
    const int n = matrix.size();
    int halfX;
    int halfY;

    if (n % 2 == 0)
    {
        halfX = halfY = n / 2;
    }
    else
    {
        halfX = n / 2 + 1;
        halfY = n / 2;
    }

    for (int y = 0; y < halfY; ++y)
    {
        for (int x = 0; x < halfX; ++x)
        {
            int temp = matrix[y][x];
            matrix[y][x] = matrix[n - 1 - x][y];
            matrix[n - 1 - x][y] = matrix[n - 1 - y][n - 1 - x];
            matrix[n - 1 - y][n - 1 - x] = matrix[x][n - 1 - y];
            matrix[x][n - 1 - y] = temp;
        }
    }
}
