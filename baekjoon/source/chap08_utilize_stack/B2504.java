import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

/**
 * B2504
 */
public class B2504 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();

        boolean isValid = true;
        int ans = 0;
        int count = 1;
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < str.length(); ++i) {
            char c = str.charAt(i);

            if (c == '(') {
                stk.push(c);
                count *= 2;
                continue;
            }

            if (c == '[') {
                stk.push(c);
                count *= 3;
                continue;
            }

            if (c == ')') {
                if (stk.isEmpty() || stk.peek() != '(') {
                    isValid = false;
                    break;
                }

                if (str.charAt(i - 1) == '(') {
                    ans += count;
                }
                count /= 2;
                stk.pop();
                continue;
            }

            if (c == ']') {
                if (stk.isEmpty() || stk.peek() != '[') {
                    isValid = false;
                    break;
                }

                if (str.charAt(i - 1) == '[') {
                    ans += count;
                }
                count /= 3;
                stk.pop();
                continue;
            }
        }

        if (!stk.isEmpty() || isValid == false) {
            ans = 0;
        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}
