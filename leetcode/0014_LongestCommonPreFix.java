// [leetcode 0014] Longest Common Prefix
import java.util.Arrays;

class Solution
{
    public String longestCommonPrefix(String[] strs)
    {
        if (strs.length == 0)
        {
            return new String("");
        }

        Arrays.sort(strs, new Comparator<String>()
        {
            @Override
            public int compare(String rhs, String lhs)
            {
                return rhs.length() - lhs.length();
            }
        });

        String pivot = strs[0];

        for (int i = 0; i < pivot.length(); ++i)
        {
            for (int j = 1; j < strs.length; ++j)
            {
                if (pivot.charAt(i) != strs[j].charAt(i))
                {
                    return pivot.substring(0, i);
                }
            }
        }

        return pivot;
    }
}
