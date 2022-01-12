bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int col = 0;
    int row = matrix[0].size() - 1;

    while (row >= 0 && col < matrix.size())
    {
        if (matrix[col][row] == target)
        {
            return true;
        }

        if (matrix[col][row] > target)
        {
            row--;
        }
        else if (matrix[col][row] < target)
        {
            col++;
        }
    }

    return false;
}
