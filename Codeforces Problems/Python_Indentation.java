import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * https://codeforces.com/problemset/problem/909/C
 */
public class Python_Indentation {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        int N = Integer.parseInt(rs.readLine().trim()), indent = 1;
        long k[] = new long[N+1], MOD = 1_000_000_007;
        k[1] = 1;
        // O(N*maxIndent)
        while (N-- > 0) {
            if (rs.readLine().charAt(0) == 'f')
                ++indent;
            else
                for (int i = 1; i <= indent; ++i) {
                    k[i] += k[i - 1];
                    if (k[i] >= MOD * MOD)
                        k[i] -= MOD * MOD;
                    for (int j = 0; j < k.length; j++) {
                        System.out.print(k[j] + " ");
                    }
                    System.out.println();
                }
        }
        System.out.println(k[indent] % MOD);
        rs.close();
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

// O(n^2) solution
// N = Integer.parseInt(rs.readLine().trim());
// int dp[][] = new int[N][N];
// boolean isF[] = new boolean[N];
// int indent[] = new int[N];
// for (int i = 0; i < N; i++) isF[i] = rs.readLine().charAt(0) == 'f';

// dp[0][0] = 1;
// for (int i = 1; i < N; i++) {
//     // suffix for i-1
//     int suf[] = new int[N];
//     suf[N-1] = dp[i][N-1];
//     for (int j = N-2; j >= 0; j--) {
//         suf[j] = suf[j + 1] + dp[i-1][j];
//         if (suf[j] >= MOD)
//             suf[j] -= MOD;
//     }
//     for (int j = 0; j < N; j++) {
//         if (isF[i-1]) {
//             // forced to indent since last line was 'f'
//             if (j != 0) dp[i][j] = dp[i-1][j-1];
//         } else  {
//             // have all options since last line was 's'
//             dp[i][j] = suf[j];
//         }
//     }
// }
// long sum = 0;
// for (int i = 0; i < N; i++) {
//     sum += dp[N-1][i];
//     if (sum >= MOD)
//         sum -= MOD;
// }
// System.out.println(sum);