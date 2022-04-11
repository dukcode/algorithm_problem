import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B6198_1
 */
public class B6198_1 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        Stack<Integer> stk = new Stack<>();
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            int height = Integer.parseInt(br.readLine());

            while (!stk.isEmpty() && stk.peek() <= height) {
                stk.pop();
            }
            ans += stk.size();
            stk.push(height);
        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}


