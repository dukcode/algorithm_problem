import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.LinkedList;

/**
 * B18258
 */
public class B18258 {

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        Deque<Integer> q = new LinkedList<>();
        while (N-- > 0) {
            String[] commands = br.readLine().split(" ");
            String cmd = commands[0];

            switch (cmd) {
                case "push":
                    q.addLast(Integer.parseInt(commands[1]));
                    break;
                case "pop":
                    bw.write(q.isEmpty() ? String.valueOf(-1) : String.valueOf(q.pollFirst()));
                    bw.newLine();
                    break;
                case "size":
                    bw.write(String.valueOf(q.size()));
                    bw.newLine();
                    break;
                case "empty":
                    bw.write(q.isEmpty() ? String.valueOf(1) : String.valueOf(0));
                    bw.newLine();
                    break;
                case "front":
                    bw.write(q.isEmpty() ? String.valueOf(-1) : String.valueOf(q.peekFirst()));
                    bw.newLine();
                    break;
                case "back":
                    bw.write(q.isEmpty() ? String.valueOf(-1) : String.valueOf(q.peekLast()));
                    bw.newLine();
                    break;
                default:
                    break;
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
