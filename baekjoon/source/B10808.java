import java.util.Arrays;
import java.util.Scanner;

/**
 * B10808
 */
class Main {

    static int[] freq = new int[26];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        for (int i = 0; i < s.length(); ++i) {
            freq[s.charAt(i) - 'a']++;
        }

        Arrays.stream(freq).forEach(i -> System.out.print(i + " "));
        System.out.println();

        sc.close();
    }
}
