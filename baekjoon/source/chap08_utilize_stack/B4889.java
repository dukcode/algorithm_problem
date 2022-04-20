import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


/**
 * B4889
 */
public class B4889 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int ord = 0;
        while (true) {
            ord++;
            String str = br.readLine();
            if (str.charAt(0) == '-') {
                break;
            }

            int ans = 0;
            Stack<Character> stk = new Stack<>();
            for (int i = 0; i < str.length(); ++i) {
                char c = str.charAt(i);

                if (c == '{') {
                    stk.push(c);
                } else {
                    if (stk.isEmpty()) {
                        stk.push('{');
                        ans++;
                        continue;
                    }

                    if (stk.peek() == '{') {
                        stk.pop();
                    } else {
                        stk.push(c);
                    }
                }
            }

            ans += stk.size() / 2;
            bw.write(String.valueOf(ord));
            bw.write(". ");
            bw.write(String.valueOf(ans));
            bw.newLine();
        }


        bw.flush();
        bw.close();
        br.close();
    }
}


