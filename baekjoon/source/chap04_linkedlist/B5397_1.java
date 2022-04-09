import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Stack;
import java.util.stream.Collectors;


/**
 * B5397
 */
public class B5397 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- != 0) {
            char[] keylog = br.readLine().toCharArray();
            LinkedList<Character> ans = new LinkedList<>();
            ListIterator<Character> it = ans.listIterator();

            for (int i = 0; i < keylog.length; ++i) {
                switch (keylog[i]) {
                    case '<':
                        if (!it.hasPrevious()) {
                            break;
                        }
                        it.previous();
                        break;
                    case '>':
                        if (!it.hasNext()) {
                            break;
                        }
                        it.next();
                        break;
                    case '-':
                        if (!it.hasPrevious()) {
                            break;
                        }
                        it.previous();
                        it.remove();
                        break;
                    default:
                        it.add(keylog[i]);
                        break;
                }
            }

            StringBuilder sb = new StringBuilder();
            for (char c : ans) {
                sb.append(c);
            }
            bw.write(sb.toString());
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();
    }
}


