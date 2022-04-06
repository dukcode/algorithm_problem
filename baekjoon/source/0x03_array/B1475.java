import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.stream.IntStream;


/**
 * B1475
 */
public class B1475 {

    public static int[] arr = new int[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String roomNum = br.readLine();

        for (int i = 0; i < roomNum.length(); ++i) {
            int num = (int)(roomNum.charAt(i) - '0');
            arr[num]++;
        }

        int sum = arr[6] + arr[9];
        if (sum % 2 == 0) {
            arr[6] = sum / 2;
        } else {
            arr[6] = sum / 2 + 1;
        }
        arr[9] = sum / 2;

        int ans = IntStream.of(arr).max().orElse(0);
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }
}
