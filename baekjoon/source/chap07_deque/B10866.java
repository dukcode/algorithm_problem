import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


/**
 * B10866
 */
public class B10866 {

    public static final int MX = 10000;
    public static int[] arr = new int[2 * MX + 1];
    public static int head = MX;
    public static int tail = MX;

    public static void push_front(int num) {
        arr[--head] = num;
    }

    public static void push_back(int num) {
        arr[tail++] = num;
    }

    public static int pop_front() {
        if (head == tail) {
            return -1;
        }
        return arr[head++];
    }

    public static int pop_back() {
        if (head == tail) {
            return -1;
        }
        return arr[--tail];
    }

    public static int size() {
        return tail - head;
    }

    public static int empty() {
        return tail == head ? 1 : 0;
    }

    public static int front() {
        if (head == tail) {
            return -1;
        }
        return arr[head];
    }

    public static int back() {
        if (head == tail) {
            return -1;
        }
        return arr[tail - 1];
    }



    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        while (N-- > 0) {
            String[] cmds = br.readLine().split(" ");
            String cmd = cmds[0];

            switch (cmd) {
                case "push_front":
                    push_front(Integer.parseInt(cmds[1]));
                    break;
                case "push_back":
                    push_back(Integer.parseInt(cmds[1]));
                    break;
                case "pop_front":
                    bw.write(String.valueOf(pop_front()));
                    bw.newLine();
                    break;
                case "pop_back":
                    bw.write(String.valueOf(pop_back()));
                    bw.newLine();
                    break;
                case "size":
                    bw.write(String.valueOf(size()));
                    bw.newLine();
                    break;
                case "empty":
                    bw.write(String.valueOf(empty()));
                    bw.newLine();
                    break;
                case "front":
                    bw.write(String.valueOf(front()));
                    bw.newLine();
                    break;
                case "back":
                    bw.write(String.valueOf(back()));
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


