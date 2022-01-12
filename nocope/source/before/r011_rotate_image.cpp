// r011_rotate_image.cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void rotate(vector<vector<int>>& matrix)
    {
        const int n = matrix.size();
    
        int halfY;
        int halfX;

        if (n % 2 == 0)
        {
            halfY = halfX = n / 2;
        }
        else
        {
            halfY = n / 2;
            halfX = n / 2 + 1;
        }
    
        //  n - 1 - newX = oldY
        //  newY = oldX
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
};

int main(void)
{

    return 0;
}
