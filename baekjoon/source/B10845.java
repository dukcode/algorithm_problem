import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * B10845
 */
public class B10845 {
    private static int[] data = new int[10005];
    private static int head = 0;
    private static int tail = 0;

    public static void push(int value) {
        data[tail++] = value;
    }

    public static int pop() {
        if (empty() == 1) {
            return -1;
        }
        return data[head++];
    }

    public static int empty() {
        if (head == tail) {
            return 1;
        }
        return 0;
    }

    public static int size() {
        return tail - head;
    }

    public static int front() {
        if (empty() == 1) {
            return -1;
        }
        return data[head];
    }

    public static int back() {
        if (empty() == 1) {
            return -1;
        }
        return data[tail - 1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int numCommand = Integer.parseInt(br.readLine());
        while (numCommand-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            switch (command) {
                case "push":
                    int value = Integer.parseInt(st.nextToken());
                    push(value);
                    break;
                case "pop":
                    bw.write(pop() + "\n");
                    break;
                case "size":
                    bw.write(size() + "\n");
                    break;
                case "empty":
                    bw.write(empty() + "\n");
                    break;
                case "front":
                    bw.write(front() + "\n");
                    break;
                case "back":
                    bw.write(back() + "\n");
                    break;
                default:
                    break;
            }
        }

        br.close();
        bw.close();
    }
}
