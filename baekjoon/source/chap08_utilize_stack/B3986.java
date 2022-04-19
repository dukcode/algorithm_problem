import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B3986
 */
public class B3986 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        int ans = 0;
        while (N-- > 0) {
            String str = br.readLine();

            Stack<Character> stk = new Stack<>();
            for (int i = 0; i < str.length(); ++i) {
                char c = str.charAt(i);
                if (stk.isEmpty()) {
                    stk.push(c);
                    continue;
                }

                if (stk.peek() == c) {
                    stk.pop();
                    continue;
                } else {
                    stk.push(c);
                }
            }

            if (stk.isEmpty()) {
                ans++;
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}


