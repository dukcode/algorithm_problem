import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Stack;

/**
 * B6549
 */
public class B6549 {

    static class Pair {
        private int height;
        private int idx;

        Pair (int height, int idx) {
            this.height = height;
            this.idx = idx;
        }

        public int getHeight() {
            return height;
        }

        public int getIdx() {
            return idx;
        }

        @Override
        public String toString() {
            return "[" + height + ", " + idx + "]";
        }
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String[] tokens = br.readLine().trim().split(" ");
            int countRectangle = Integer.parseInt(tokens[0]);
            if (countRectangle == 0) {
                break;
            }

            int[] heights = Arrays.stream(tokens)
                .skip(1)
                .mapToInt(Integer::parseInt)
                .toArray();
            long maxArea = 0;
            Stack<Pair> stk = new Stack<>();

            for (int i = 0; i < heights.length; ++i) {
                int height = heights[i];
                int idx = i;

                while (!stk.isEmpty() && stk.peek().getHeight() >= height) {
                    maxArea = Math.max(maxArea, (long)stk.peek().getHeight() * (i - stk.peek().getIdx()));
                    idx = stk.peek().getIdx();
                    stk.pop();
                }
                stk.push(new Pair(height, idx));
            }

            for (Pair p : stk) {
                maxArea = Math.max(maxArea, (heights.length - p.getIdx()) * (long)p.getHeight());
            }

            bw.write(maxArea + "\n");
        }


        bw.flush();
        bw.close();
        br.close();
    }
}
