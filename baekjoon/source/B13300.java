import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;


/**
 * B13300
 */
public class B13300 {

    public static final int[][] arr = new int[2][7];

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine(), " ");
            int sex = Integer.parseInt(st.nextToken());
            int grade = Integer.parseInt(st.nextToken());

            arr[sex][grade]++;
        }

        int ans = Arrays.stream(arr)
            .flatMapToInt(Arrays::stream)
            .map(i -> (i + (K - 1)) / K)
            .sum();

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }
}
