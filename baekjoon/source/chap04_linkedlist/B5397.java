import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B5397
 */
public class B5397 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- != 0) {
            char[] keylog = br.readLine().toCharArray();

            Stack<Character> before = new Stack<>();
            Stack<Character> after = new Stack<>();

            for (int i = 0; i < keylog.length; ++i) {
                switch (keylog[i]) {
                    case '<':
                        if (before.isEmpty()) {
                            break;
                        }
                        after.push(before.pop());
                        break;
                    case '>':
                        if (after.isEmpty()) {
                            break;
                        }
                        before.push(after.pop());
                        break;
                    case '-':
                        if (before.isEmpty()) {
                            break;
                        }
                        before.pop();
                        break;
                    default:
                        before.push(keylog[i]);
                        break;
                }
            }

            while (!before.isEmpty()) {
                after.push(before.pop());
            }

            StringBuilder ans = new StringBuilder();
            while (!after.isEmpty()) {
                ans.append(after.pop());
            }
            bw.write(ans.toString());
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();
    }
}


