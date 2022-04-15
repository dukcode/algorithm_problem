import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B10799_1
 */
public class B10799_1 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] charArr = br.readLine().toCharArray();

        int ans = 0;
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < charArr.length; ++i) {
            if (charArr[i] == '(') {
                stk.push(charArr[i]);
            } else {
                if (charArr[i - 1] == '(') {
                    ans += stk.size();
                } else {
                    ans++;
                }
                stk.pop();
            }

        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


