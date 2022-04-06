import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


/**
 * B11328
 */
public class B11328 {

    public static final int ALPABET_NUM = 26;

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        Loop:
        while (N-- != 0) {
            int[] arr = new int[ALPABET_NUM];
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String firstStr = st.nextToken();
            String secondStr = st.nextToken();

            if (firstStr.length() != secondStr.length()) {
                    bw.write("Impossible");
                    bw.newLine();
                    continue Loop;
            }

            for (int i = 0; i < firstStr.length(); ++i) {
                arr[(int)(firstStr.charAt(i) - 'a')]++;
                arr[(int)(secondStr.charAt(i) - 'a')]--;
            }

            for (int i = 0; i < ALPABET_NUM; ++i) {
                if (arr[i] != 0) {
                    bw.write("Impossible");
                    bw.newLine();
                    continue Loop;
                }
            }

            bw.write("Possible");
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
