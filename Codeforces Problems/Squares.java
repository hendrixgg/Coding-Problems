import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * https://codeforces.com/contest/123/problem/B
 * 
 * essentially the bad squares from the abs(x + y) form lines y = -x spaced out
 * by 2*a and the bad square from the abs(x - y) form lines y = x spaced out by
 * 2*b
 * 
 * the solution is to figure out what sectors the start and end squares are in
 * and from this we can find out how many of the lines of bad squares we have to cross.
 */
public class Squares {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        long a = rs.nextLong(), b = rs.nextLong(), x1 = rs.nextLong(), y1 = rs.nextLong(), x2 = rs.nextLong(), y2 = rs.nextLong();
        long a1_id = (x1 + y1) / (2 * a), b1_id = (x1 - y1) / (2 * b);
        // when numbers are negative they get rounded up not down
        // also don't have to worry about dividing evenly since 
        // start and end positions are guaranteed not bad
        if (x1 + y1 < 0) a1_id--;
        if (x1 - y1 < 0) b1_id--;

        long a2_id = (x2 + y2) / (2 * a), b2_id = (x2 - y2) / (2 * b);
        if (x2 + y2 < 0) a2_id--;
        if (x2 - y2 < 0) b2_id--;
        long a_moves = Math.abs(a1_id - a2_id);
        long b_moves = Math.abs(b1_id - b2_id);

        System.out.println(Math.max(a_moves, b_moves));
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
