#include <iostream>
#include <vector>

void rotate(std::vector< std::vector<int> >& matrix)
{
    const int n = matrix.size();
    int halfY; int halfX;

    if (n % 2 == 0)
    {
        halfY = halfX = n / 2;
    }
    else
    {
        halfY = n / 2;
        halfX = n / 2 + 1;
    }

    for (int y = 0; y < halfY; y++)
    {
        for (int x = 0; x < halfX; x++)
        {
            int temp = matrix[n - 1 - x][y];
            matrix[n - 1 - x][y] = matrix[n - 1 - y][n - 1 - x];
            matrix[n - 1 - y][n - 1 - x] = matrix[x][n - 1 - y];
            matrix[x][n - 1 - y] = matrix[y][x];
            matrix[y][x] = temp;
        }
    }
}

int main(void)
{
    int n = 20;
    std::vector< std::vector<int> > matrix(n, std::vector<int>(n, 0));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            matrix[y][x] = y * n + x;
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            std::cout << matrix[y][x] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    rotate(matrix);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            std::cout << matrix[y][x] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
