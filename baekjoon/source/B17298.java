import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;


/**
 * B17298
 */
public class B17298 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.valueOf(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; ++i) {
            arr[i] = Integer.valueOf(st.nextToken());
        }

        int[] ans = new int[N];
        Stack<Integer> stk = new Stack<>();
        for (int i = N - 1; i >= 0; --i) {
            while (!stk.empty() && stk.peek() <= arr[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = stk.peek();
            }
            stk.push(arr[i]);
        }

        for (int i = 0; i < N; ++i) {
            bw.write(ans[i] + " ");
        }

        bw.close();
        br.close();
    }
}
