import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {

    static class Point {
        public int y;
        public int x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "(" + y + ", " + x + ")";
        }

        public boolean isOutOfRange() {
            if (y < 0 || y >= height || x < 0 || x >= width) {
                return true;
            }
            return false;
        }
    }

    static int[][] board = new int[][] { { 1, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

    static int height = 7;
    static int width = 10;
    static boolean[][] visited = new boolean[height][width];

    static int[] dy = new int[] {1, -1, 0, 0};
    static int[] dx = new int[] {0, 0, -1, 1};

    static Queue<Point> q = new LinkedList<>();

    public static void main(String[] args) {
        printBoard();

        visited[0][0] = true;
        board[0][0] = 4;
        q.offer(new Point(0, 0));
        while (!q.isEmpty()) {
            Point p = q.poll();
            for (int i = 0; i < 4; ++i) {
                Point np = new Point(p.y + dy[i], p.x + dx[i]);
                if (np.isOutOfRange()) {
                    continue;
                }

                if (visited[np.y][np.x] == true) {
                    continue;
                }

                if (board[np.y][np.x] != 1) {
                    continue;
                }

                visited[np.y][np.x] = true;
                board[np.y][np.x] = 4;
                q.offer(np);
            }
        }

        printBoard();
    }

    public static void printBoard() {
        for (int[] line : board) {
            System.out.println(Arrays.toString(line));
        }
        System.out.println();
    }
}
