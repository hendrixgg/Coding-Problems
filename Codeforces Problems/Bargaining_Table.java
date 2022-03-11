import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * https://codeforces.com/problemset/problem/22/B
 * 
 * this gives the perimeter of the largest rectangle that only contains 0's
 */
public class Bargaining_Table {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        int N = rs.nextInt(), M = rs.nextInt();
        int grid[][] = new int[N + 1][];
        int pre[][] = new int[N + 1][M + 1];
        rs.nextLine();
        for (int i = 1; i <= N; i++) {
            grid[i] = rs.readBytes(M + 1);
        }
        // printGrid(pre);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                pre[i][j] = grid[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        prefix_sum_2D(grid, pre, N, M);

        // brute_Force(grid, N, M);
        
        rs.close();
    }

    // O((N*M)^2)
    static void prefix_sum_2D(int grid[][], int pre[][], int N, int M) {
        int max_p = 0;
        for (int r1 = 1; r1 <= N; r1++) {
            for (int c1 = 1; c1 <= M; c1++) {
                if (grid[r1][c1] == 1) continue;
                for (int r2 = r1; r2 <= N; r2++) {
                    for (int c2 = c1; c2 <= M; c2++) {
                        int ones = pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
                        if (ones == 0) max_p = Math.max(max_p, 2 * (r2 - r1 + 1) + 2 * (c2 - c1 + 1));
                    }
                }
            }
        }
        System.out.println(max_p);
    }

    // O((N*M)^3)
    static void brute_Force(int grid[][], int N, int M) {
        int max_p = 0;
        for (int r1 = 1; r1 <= N; r1++) {
            for (int c1 = 1; c1 <= M; c1++) {
                if (grid[r1][c1] == 1) continue;
                for (int r2 = r1; r2 <= N; r2++) {
                    for (int c2 = c1; c2 <= M; c2++) {
                        if (checkGrid(grid, r1, c1, r2, c2)) {
                            max_p = Math.max(max_p, 2 * (r2 - r1 + 1) + 2 * (c2 - c1 + 1));
                        }
                    }
                }
            }
        }
        System.out.println(max_p);;
    }

    // returns false if there is a 1 in the region
    static boolean checkGrid(int[][] grid, int r1, int c1, int r2, int c2) {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1)
                    return false;
            }
        }
        return true;
    }

    static void printGrid(int[][] grid) {
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                System.out.printf("%3d", grid[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    
    
    /**
     * Fast input reader
     */
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
    
        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
    
        /**
         * Read data from a file.
         * @param file_name
         * @throws IOException
         */
        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
    
        /**
         * Reads one line of input of a standard length of 64 characters or until the
         * newline character ('\n') is found.
         * 
         * @return a String of the input data
         * @throws IOException
         */
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
    
        /**
         * Reads one line of input of a length specified by the argument {@code length} or
         * until the newline character ("\n") is found.
         * 
         * @param length
         * @return a String of the input data
         * @throws IOException
         */
        public String readLine(int length) throws IOException {
            byte[] buf = new byte[length]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c < ' ')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
    
        /**
         * Reads one line of input of a standard length of 64 characters or until the
         * newline character ('\n') is found.
         * 
         * The last index of the array contains the length of the input.
         * 
         * @return a byte array of the char values.
         * @throws IOException
         */
        public int[] readBytes() throws IOException {
            int[] buf = new int[65];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c < ' ') {
                    buf[64] = cnt;
                    nextLine();
                    break;
                }
                buf[cnt++] = c;
            }
            return buf;
        }
    
        /**
         * Reads one line of input of a specified by the argument {@code length} or
         * until the newline character ('\n') is found.
         * 
         * The last index of the array contains the length of the input.
         * 
         * @return a byte array of the char values.
         * @throws IOException
         * 
         * changed so it returns the actual digit
         * also so that the array is 1 indexed
         */
        public int[] readBytes(int length) throws IOException {
            int[] buf = new int[length + 1];
            int cnt = 1, c;
            while ((c = read()) != -1) {
                if (c < ' ') {
                    nextLine();
                    break;
                }
                buf[cnt++] = c - '0';
            }
            return buf;
        }
    
        /**
         * Advances the Reader to the next line.
         * 
         * @throws IOException
         */
        public void nextLine() throws IOException {
            int c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    return;
            }
        }
    
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
    
        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
    
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)
                return -ret;
            return ret;
        }
    
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
    
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
    
        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
