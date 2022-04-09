import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


/**
 * 0000
 */
public class B3273 {

    private static int[] arr = new int[2000001];

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int x = Integer.parseInt(br.readLine());

        int ans = 0;
        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());
            arr[num]++;
            if (num * 2 == x) {
                continue;
            }

            if (x - num >= 0) {
                ans += arr[x-num];
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


