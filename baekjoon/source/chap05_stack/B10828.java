import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * B10828
 */
class B10828 {

    public static int[] stack = new int[10005];
    public static int pos = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.valueOf(br.readLine());

        while (n-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            String cmd = st.nextToken();

            switch (cmd) {
                case "push":
                    push(Integer.valueOf(st.nextToken()));
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
                case "top":
                    bw.write(top() + "\n");
                    break;
                default:
                    break;
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }

    public static void push(int value) {
        stack[pos++] = value;
    }

    public static int pop() {
        if (pos == 0) {
            return -1;
        }
        int value = stack[--pos];
        return value;
    }

    public static int size() {
        return pos;
    }

    public static int empty() {
        return pos == 0 ? 1 : 0;
    }

    public static int top() {
        if (pos == 0) {
            return -1;
        }
        return stack[pos - 1];
    }





}
