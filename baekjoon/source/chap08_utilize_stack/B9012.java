import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


/**
 * B9012
 */
public class B9012 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        while (N-- > 0) {
            String str = br.readLine();
            
            if (str.length() % 2 != 0) {
                bw.write("NO");
                bw.newLine();
                continue;
            }

            int cnt = 0;
            int ans = 0;
            for (int i = 0; i < str.length(); ++i) {
                char c = str.charAt(i);

                if (c == '(') {
                    cnt++;
                } else {
                    cnt--;
                    if (cnt == -1) {
                        cnt = 1;
                        ans++;
                    }
                }
            }

            ans += cnt / 2;
            if (ans != 0) {
                bw.write("NO");
            } else {
                bw.write("YES");
            }
            bw.newLine();
        }


        bw.flush();
        bw.close();
        br.close();
    }
}


