// [leetcode 74] Search a 2D Matrix
#include <vector>

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
/Users/dukcode/Pictures/Photos\ Library.photoslibrary/originals/7/70E3F5F2-D09F-49EB-993D-DD5BC152AA11.heic     const int sizeY = matrix.size();
    const int sizeX = matrix[0].size();
    int y = sizeY - 1;
    int x = 0;

    while (x < sizeX && y >= 0)
    {
        if (matrix[y][x] == target)
        {
            return true;
        }

        if (matrix[y][x] > target)
        {
            y--;
        }
        else
        {
            x++;
        }
    }

    return false;
}
