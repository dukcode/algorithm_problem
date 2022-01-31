class Solution {
    public int balancedStringSplit(String s) {
        int numBalancedStrings = 0;
        int count = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == 'L') {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                numBalancedStrings++;
            }
        }

        return numBalancedStrings;
    }
}
