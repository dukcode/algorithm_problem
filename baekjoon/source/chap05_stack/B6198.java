import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;


/**
 * B6198
 */
public class B6198 {

    static class Building {
        int height;
        int countSkip;

        Building (int height, int countSkip) {
            this.height = height;
            this.countSkip = countSkip;
        }
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] heights = new int[N];
        for (int i = 0; i < N; ++i) {
            heights[i] = Integer.parseInt(br.readLine());
        }

        Stack<Building> stk = new Stack<>();
        long ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            int height = heights[i];
            int countSkip = 0;

            while (!stk.isEmpty() && height > stk.peek().height) {
                countSkip += (stk.peek().countSkip + 1);
                stk.pop();
            }
            ans += countSkip;
            stk.push(new Building(height, countSkip));
        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}


