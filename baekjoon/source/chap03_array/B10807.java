import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


/**
 * B10807
 */
public class B10807 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.valueOf(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int v = Integer.valueOf(br.readLine());

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int num = Integer.parseInt(st.nextToken());
            if (num == v) {
                ans++;
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}
