import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B10799
 */
public class B10799 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] charArr = br.readLine().toCharArray();

        int ans = 0;
        int cnt = 0;
        Stack<Character> stk = new Stack<>();
        for (char c : charArr) {
            if (c == '(') {
                stk.push(c);
                cnt++;
                continue;
            }

            if (stk.peek() == '(' && c == ')') {
                stk.push(c);
                cnt--;
                ans += cnt;
                continue;
            }

            if (c == ')') {
                cnt--;
                ans++;
                continue;
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


