import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;


/**
 * B6549
 */
public class B6549 {

    static class Rectangle {
        int height;
        int idx;

        Rectangle (int height, int idx) {
            this.height = height;
            // min idx left on the block with which
            // can make rectangle with this height
            this.idx = idx;     
        }
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) {
                break;
            }

            long maxArea = -1;
            Stack<Rectangle> stk = new Stack<>();
            for (int i = 0; i < n; ++i) {
                int height = Integer.parseInt(st.nextToken());
                int idx = i;

                while (!stk.isEmpty() && stk.peek().height >= height) {
                    maxArea = Math.max(maxArea, (i - stk.peek().idx) * (long)stk.peek().height);
                    idx = stk.peek().idx;
                    stk.pop();
                }
                stk.push(new Rectangle(height, idx));
            }

            while (!stk.isEmpty()) {
                maxArea = Math.max(maxArea, (n - stk.peek().idx) * (long)stk.peek().height);
                stk.pop();
            }

            bw.write(String.valueOf(maxArea));
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();
    }
}


