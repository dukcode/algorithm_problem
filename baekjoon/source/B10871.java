import java.util.Scanner;

/**
 * B10871
 */
public class B10871 {
    static int n;
    static int x;
    static int t;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        x = sc.nextInt();
        while (n-- > 0) {
            t = sc.nextInt();
            if (t < x) System.out.print(t + " ");
        }
        sc.close();
    }
}
