import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


/**
 * B4889_1
 */
public class B4889_1 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int ord = 0;
        while (true) {
            ord++;
            String str = br.readLine();
            if (str.charAt(0) == '-') {
                break;
            }

            int ans = 0;
            int cnt = 0;
            for (int i = 0; i < str.length(); ++i) {
                char c = str.charAt(i);

                if (c == '{') {
                    cnt++;
                } else {
                    cnt--;
                    if (cnt == -1) { // stk이 빈 상태에서 '}'가 들어오면 '{'로 바꾼다.
                        cnt = 1;
                        ans++;
                    }
                }
            }

            ans += cnt / 2;
            bw.write(String.valueOf(ord));
            bw.write(". ");
            bw.write(String.valueOf(ans));
            bw.newLine();
        }


        bw.flush();
        bw.close();
        br.close();
    }
}


