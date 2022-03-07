import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.ListIterator;

/**
 * B1406
 */
class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        LinkedList<Character> ll = new LinkedList<>();
        for (int i = 0; i < str.length(); ++i) {
            ll.add(str.charAt(i));
        }

        int numCommand = Integer.parseInt(br.readLine());

        ListIterator<Character> cur = ll.listIterator(ll.size());
        while (numCommand-- != 0) {
           String command = br.readLine();
           char cmd = command.charAt(0);

           switch (cmd) {
               case 'L':
                   if (cur.hasPrevious()) cur.previous();
                   break;
               case 'D':
                   if (cur.hasNext()) cur.next();
                   break;
               case 'B':
                   if (cur.hasPrevious()) {
                       cur.previous();
                       cur.remove();
                   } 
                   break;
               case 'P':
                   char c = command.charAt(2);
                   cur.add(c);
                   break;
               default:
                   break;
           }
        }

        for (Character c : ll) {
            bw.write(c);
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
