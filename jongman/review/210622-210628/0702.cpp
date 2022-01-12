// 0702.cpp

class SquareMatrix;

SquareMatrix identity(int n);

SquareMatrix pow(const SquareMatrix& A, int m)
{
    if (m == 0)
    {
        return identity(A.size());
    }

    if (m % 2 == 1)
    {
        return pow(A, m - 1) * A;
    }

    SquareMatrix half = pow(A, m / 2);

    return half * half;
}
