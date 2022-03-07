import java.util.Arrays;

public class LinkedList {

    static final int MX = 1000005;
    private static int[] dat = new int[MX];
    private static int[] pre = new int[MX];
    private static int[] nxt = new int[MX];
    private static int unused = 1;

    static {
        Arrays.fill(pre, -1);
        Arrays.fill(nxt, -1);
    }

    static void traverse() {
        int cur = nxt[0];

        while (cur != -1) {
            System.out.print(dat[cur] + " ");
            cur = nxt[cur];
        }
        System.out.println();
    }

    static void insert(int addr, int num) {
        dat[unused] = num;
        pre[unused] = addr;
        nxt[unused] = nxt[addr];

        if (nxt[addr] != -1) {
            pre[nxt[addr]] = addr;
        }

        nxt[addr] = unused;
        unused++;
    }

    static void erase(int addr) {
        nxt[pre[addr]] = nxt[addr];
        if (nxt[addr] != -1) {
            pre[nxt[addr]] = pre[addr];
        }
    }

    public static void main(String[] args) {
        insert(0, 10);
        traverse();
        insert(0, 30);
        traverse();
        insert(2, 40);
        traverse();
        insert(1, 20);
        traverse();
        insert(4, 70);
        traverse();
    }


    
}
