#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target);

int main(void)
{
    int n = 3;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

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

    std::cout << searchMatrix(matrix, -10) << std::endl;

    return 0;
}

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
{
    int start = 0;
    int end = matrix.size() - 1;

    int pivot;
    while (start <= end)
    {
        pivot = (start + end) / 2;
        if (matrix[pivot][0] == target)
        {
            return true;
        }
        
        if (matrix[pivot][0] < target)
        {
            start = pivot + 1;
        }
        else if (matrix[pivot][0] > target)
        {
            end = pivot - 1;
        }
    }
    
    int row = end;
    if (end < 0)
    {
        return false;
    }

    start = 0;
    end = matrix[0].size() - 1;

    while (start <= end)
    {
        pivot = (start + end) / 2;
        if (matrix[row][pivot] == target)
        {
            return true;
        }
        
        if (matrix[row][pivot] < target)
        {
            start = pivot + 1;
        }
        else if (matrix[row][pivot] > target)
        {
            end = pivot - 1;
        }
    }

    return false;
}
