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
 * B7576
 */
public class B7576 {

    static int width;
    static int height;

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
        width = Integer.parseInt(st.nextToken());
        height = Integer.parseInt(st.nextToken());
        dist = new int[height][width];

        Queue<Point> q = new LinkedList<>();
        for (int y = 0; y < height; ++y) {
            String[] line = br.readLine().split(" ");
            Arrays.fill(dist[y], 0);
            for (int x = 0; x < width; ++x) {
                int tomato = Integer.parseInt(line[x]);
                if (tomato == 1) {
                    q.offer(new Point(y, x));
                }

                if (tomato == 0) {
                    dist[y][x] = -1;
                }
            }
        }

        while (!q.isEmpty()) {
            Point curPoint = q.poll();
            for (int i = 0; i < 4; ++i) {
                int ny = curPoint.y + dy[i];
                int nx = curPoint.x + dx[i];
                Point newPoint = new Point(ny, nx);

                if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                    continue;
                }

                if (dist[ny][nx] != -1) {
                    continue;
                }

                dist[ny][nx] = dist[curPoint.y][curPoint.x] + 1;
                q.offer(newPoint);
            }
        }

        int ans = 0;
        Loop: for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (dist[y][x] == -1) {
                    ans = -1;
                    break Loop;
                }
                ans = Math.max(ans, dist[y][x]);
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}


