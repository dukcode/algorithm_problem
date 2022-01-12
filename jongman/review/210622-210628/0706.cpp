// 0706.cpp

string reverse(string::iterator& it)
{
    char head = *(it++);

    if (head != 'x')
    {
        return string(1, head);
    }
    else
    {
        string leftUpper = reverse(it);
        string rightUpper = reverse(it);
        string leftLower = reverse(it);
        string rightLower = reverse(it);

        return string("x") + leftLower + rightLower + leftUpper + rightUpper;
    }
}
