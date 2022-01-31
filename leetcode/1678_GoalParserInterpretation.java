class Solution {
    public String interpret(String command) {
        StringBuilder str = new StringBuilder();

        for (int i = 0; i < command.length(); ++i) {
            char c = command.charAt(i);

            if (c == 'G') {
                str.append('G');
                continue;
            }

            if (c == '(') {
                char nextC = command.charAt(i + 1);
                if (nextC == ')') {
                    str.append('o');
                }
                else {
                    str.append("al");
                }
            }
        }

        return str.toString();
    }
}
