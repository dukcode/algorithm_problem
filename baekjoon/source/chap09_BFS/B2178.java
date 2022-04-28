import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


/**
 * B2178
 */
public class B2178 {

    static int height;
    static int width;

    static int[][] board;
    static int[][] dist;

    static class Point {
        int y;
        int x;

        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        height = Integer.parseInt(st.nextToken());
        width = Integer.parseInt(st.nextToken());
        board = new int[height][];
        dist = new int[height][width];

        for (int i = 0; i < height; ++i) {
            board[i] = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
            Arrays.fill(dist[i], -1);
        }

        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(0, 0));
        dist[0][0] = 1;

        while (!q.isEmpty()) {
            Point p = q.poll();
            int d = dist[p.y][p.x];
            for (int i = 0; i < 4; ++i) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                Point np = new Point(ny, nx);

                if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                    continue;
                }

                if (board[ny][nx] != 1) {
                    continue;
                }

                if (dist[ny][nx] != -1) {
                    continue;
                }

                dist[ny][nx] = d + 1;
                q.offer(np);
            }
        }

        bw.write(String.valueOf(dist[height - 1][width - 1]));
        bw.newLine();

        bw.flush();
        bw.close();
        br.close();
    }
}


