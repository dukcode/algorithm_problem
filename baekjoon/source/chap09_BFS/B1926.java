import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


/**
 * B1926
 */
public class B1926 {
        
    static BufferedReader br;
    static BufferedWriter bw;

    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    static int height;
    static int width;

    static int[][] board;
    static boolean[][] visited;

    static int count;
    static int maxArea;

    static void solve() throws IOException {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (visited[y][x] == true || board[y][x] != 1) {
                    continue;
                }
                int area = 0;

                count++;
                area++;
                Queue<Point> q = new LinkedList<>();
                q.offer(new Point(y, x));
                visited[y][x] = true;

                while (!q.isEmpty()) {
                    Point p = q.poll();
                    for (int dir = 0; dir < 4; ++dir) {
                        int ny = p.y + dy[dir];
                        int nx = p.x + dx[dir];
                        Point np = new Point(ny, nx);

                        if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                            continue;
                        }

                        if (visited[ny][nx] == true) {
                            continue;
                        }

                        if (board[ny][nx] != 1) {
                            continue;
                        }

                        q.offer(np);
                        visited[ny][nx] = true;
                        area++;
                    }
                }
                maxArea = Math.max(maxArea, area);
            }
        }

        bw.write(String.valueOf(count));
        bw.newLine();
        bw.write(String.valueOf(maxArea));
        bw.newLine();
    }

    static void init() throws IOException {
        // br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        height = Integer.parseInt(st.nextToken());
        width = Integer.parseInt(st.nextToken());

        board = new int[height][];
        visited = new boolean[height][width];

        for (int i = 0; i < height; ++i) {
            board[i] = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
            Arrays.fill(visited[i], false);
        }
    }

    static class Point {
        int y;
        int x;
        
        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        solve();

        bw.flush();
        bw.close();
        br.close();
    }
}


