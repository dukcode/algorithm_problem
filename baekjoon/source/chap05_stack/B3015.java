import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;


/**
 * B3015
 */
public class B3015 {

    static class Person {
        int height;
        int count;

        Person(int height, int count) {
            this.height = height;
            this.count = count;
        }
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        long ans = 0;
        Stack<Person> stk = new Stack<>();
        while (N-- > 0) {
            int height = Integer.parseInt(br.readLine());

            int count = 1;
            while (!stk.isEmpty() && stk.peek().height <= height) {
                ans += stk.peek().count;

                if (stk.peek().height == height) {
                    count += stk.peek().count;
                }
                stk.pop();
            }

            if (!stk.isEmpty()) {
                ans++;
            }
            stk.push(new Person(height, count));
        }
        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


