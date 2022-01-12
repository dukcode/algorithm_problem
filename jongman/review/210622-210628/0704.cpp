// 0704.cpp

vector<int> karatuba(const vector<int>& A, const vector<int>& B)
{
    int an = A.size(); int bn = B.size();

    if (an < bn)
    {
        return karatuba(B, A);
    }

    if (an == 0 || bn == 0)
    {
        return vector<int>();
    }

    if(an <= 50)
    {
        return multiply(A, B);
    }

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());;
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatuba(a1, b1);
    vector<int> z0 = karatuba(a0, b0);

    addTo(a0, a1, 0); addTo(b0, b1, 0);

    vector<int> z1 = karatuba(a0, b0);

    subFrom(z1, z0); subFrom(z0, z2);

    vector<int> ret;
    addTo(ret, z0, 0); addTo(ret, z1, half); addTo(ret, z2, half + half);

    return ret;
}
