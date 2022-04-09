import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.stream.IntStream;


/**
 * B1919
 */
public class B1919 {

    public static int[] arr = new int[26];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String firstStr = br.readLine();
        String secondStr = br.readLine();

        for (char c : firstStr.toCharArray()) {
            arr[(int)(c - 'a')]++;
        }

        for (char c : secondStr.toCharArray()) {
            arr[(int)(c - 'a')]--;
        }

        int ans = IntStream.of(arr).map(i -> i < 0 ? -i : i).sum();
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }
}


