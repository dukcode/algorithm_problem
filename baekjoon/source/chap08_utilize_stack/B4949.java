import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;


/**
 * B4949
 */
public class B4949 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String str = br.readLine();
            if (str.startsWith(".")) {
                break;
            }

            char[] charArr = str.toCharArray();
            Stack<Character> stk = new Stack<>();
            boolean ok = true;
            for (int i = 0; i < charArr.length - 1; ++i) {
                char c = charArr[i];

                if (c == '[' || c == '(') {
                    stk.push(c);
                    continue;
                }

                if (c == ']') {
                    if (stk.isEmpty() || stk.peek() != '[') {
                        ok = false;
                        break;
                    }
                stk.pop();
                }

                if (c == ')') {
                    if (stk.isEmpty() || stk.peek() != '(') {
                        ok = false;
                        break;
                    }
                stk.pop();
                }
            }

            if (stk.isEmpty() && ok == true) {
                bw.write("yes");
                bw.newLine();
            } else {
                bw.write("no");
                bw.newLine();
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}


