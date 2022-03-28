import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

/**
 * B10773
 */
public class B10773 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int k = Integer.valueOf(br.readLine());

        Stack<Integer> stack = new Stack<>();
        int sum = 0;
        while (k-- != 0) {
            int n = Integer.valueOf(br.readLine());

            if (n == 0) {
                stack.pop();
                continue;
            }

            stack.push(n);
        }

        while (!stack.empty()) {
            sum += stack.pop();
        }

        bw.write(sum + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}
