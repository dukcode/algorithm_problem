import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * B10845_1
 */
public class B18258 {

    public static Queue<Integer> q = new LinkedList<>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int numCommand = Integer.parseInt(br.readLine());
        int back = -1;
        while (numCommand-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            switch (command) {
                case "push":
                    back  = Integer.parseInt(st.nextToken());
                    q.offer(back);
                    break;
                case "pop":
                    if (q.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(q.poll() + "\n");
                    break;
                case "size":
                    bw.write(q.size() + "\n");
                    break;
                case "empty":
                    bw.write((q.isEmpty() ? 1 : 0) + "\n");
                    break;
                case "front":
                    if (q.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(q.peek() + "\n");
                    break;
                case "back":
                    if (q.isEmpty()) {
                        bw.write("-1\n");
                        break;
                    }
                    bw.write(back + "\n");
                    break;
                default:
                    break;
            }
        }

        br.close();
        bw.close();
    }
}
