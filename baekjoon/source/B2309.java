import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


/**
 * B2309
 */
public class B2309 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> dwarfs = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < 9; ++i) {
            int tall = Integer.valueOf(br.readLine());
            dwarfs.add(tall);
            sum += tall;
        }

        Loop1: for (int i = 0; i < 8; ++i) {
            for (int j = i + 1; j < 9; ++j) {
                if (sum - 100 == dwarfs.get(i) + dwarfs.get(j)) {
                    dwarfs.remove((int)j);
                    dwarfs.remove((int)i);
                    break Loop1;
                }
            }
        }

        dwarfs.stream().sorted().forEach(System.out::println);
    }
}
