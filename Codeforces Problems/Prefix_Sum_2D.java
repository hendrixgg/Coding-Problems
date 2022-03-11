import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/*
Given a 2d array of N*M integers. Given Q qureies and in each query give r1, c1, r2, c2
print the sum of the elemnts in the square represented by (r1, c1) as the top left 
corner and (r2, c2) as the bottom left corner.

Constraint:
1 <= N, M <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= r1 <= r2 <= N
1 <= c1 <= c2 <= M

test case
in:
3 3
3 6 2
8 9 2
3 4 1
2
1 1 2 2
1 2 3 3

out:
26
24
*/
public class Prefix_Sum_2D {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        int N = rs.nextInt(), M = rs.nextInt();
        int array[][] = new int[N+1][M+1];
        int pre[][] = new int[N+1][M+1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                array[i][j] = rs.nextInt();
                pre[i][j] = array[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        printGrid(pre);
        int Q = rs.nextInt();
        while (Q-- > 0) {
            int r1 = rs.nextInt(), c1 = rs.nextInt(), r2 = rs.nextInt(), c2 = rs.nextInt();
            long sum = 0;
            // Naive approach
            // for (int i = r1; i <= r2; i++) {
            //     for (int j = c1; j < c2; j++) {
            //         sum += array[i][j];
            //     }
            // }
            sum = pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
            System.out.println(sum);
        }
        
        rs.close();
    }

    static void printGrid(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
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
                if (c == '\n')
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
         */
        public int[] readBytes(int length) throws IOException {
            int[] buf = new int[length + 1];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c < ' ') {
                    buf[length] = cnt;
                    break;
                }
                buf[cnt++] = c;
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
