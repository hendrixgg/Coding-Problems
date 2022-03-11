import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * https://codeforces.com/contest/1516/problem/C
 */
public class Baby_Ehab_Partitions_Again {
    public static void main(String[] args) throws Exception {

        Reader rs = new Reader();
        int N = rs.nextInt(), sum = 0;
        ;
        int array[] = new int[N];
        for (int i = 0; i < N; i++) {
            array[i] = rs.nextInt();
            sum += array[i];
        }
        if ((sum & 1) == 1) // bitwise (and &) meaning if the first digit of sum in binary is a 1 then it is an
                            // odd number
            System.out.println("0"); // cannot partition into two sequences if sum is odd
        else {
            sum /= 2; // target
            boolean possible[] = new boolean[sum + 1];
            possible[0] = true;
            // possible[s] is true if and only if you can achieve sum s
            for (int n : array) {
                for (int s = sum - n; s >= 0; s--) { // end if it worked
                    if (possible[s])
                        possible[s + n] = true;
                }
            }
            if (possible[sum]) {
                int b = -1;
                while (b++ > -5) {
                    for (int i = 0; i < N; i++) {
                        if (((array[i] >> b) & 1) == 1) { // if an odd number
                            System.out.println("1 \n" + (i + 1));
                            b = -10;
                            break;
                        }
                    }
                }
            } else
                System.out.println("0");
        }
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
         * 
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
         * Reads one line of input of a length specified by the argument {@code length}
         * or until the newline character ("\n") is found.
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
         * Advances the Reader to the next line.
         * 
         * @throws IOException
         */
        public void nextLine() throws IOException {
            int c;
            while ((c = read()) != -1)
                if (c == '\n')
                    return;
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