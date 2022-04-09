import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringJoiner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

/**
 * B1158
 */
public class B1158 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int K = Integer.parseInt(tokens[1]);

        Queue<Integer> q = new LinkedList<>(IntStream.rangeClosed(1, N).boxed().collect(Collectors.toList()));

        StringJoiner sj = new StringJoiner(", ", "<", ">");
        int count = 0;
        while (!q.isEmpty()) {
            count++;
            int num = q.poll();
            if (count % K != 0) {
                q.offer(num);
            } else {
                sj.add(String.valueOf(num));
            }
        }
        bw.write(sj.toString());

        bw.flush();
        bw.close();
        br.close();
    }
}


