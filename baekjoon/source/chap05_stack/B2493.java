import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringJoiner;
import java.util.StringTokenizer;

/**
 * B2493
 */
public class B2493 {

    public static class Top {
        int height;
        int idx;

        Top(int height, int idx) {
            this.height = height;
            this.idx = idx;
        }
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Top> tops = new Stack<>();
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        StringJoiner sj = new StringJoiner(" ");
        for (int i = 0; i < N; ++i) {
            int height = Integer.parseInt(st.nextToken());
            while (!tops.isEmpty() && tops.peek().height < height) {
                tops.pop();
            }

            if (tops.isEmpty()) {
                sj.add(String.valueOf(0));
            } else {
                sj.add(String.valueOf(tops.peek().idx));
            }

            tops.push(new Top(height, i + 1));
        }

        bw.write(sj.toString());
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


