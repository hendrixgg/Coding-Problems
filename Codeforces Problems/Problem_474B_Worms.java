import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Problem_474B_Worms {
    public static void main(String[] args) throws IOException {

        Reader rs = new Reader();
        int n = rs.nextInt(), t = 0;
        int[] pile = new int[n + 1];
        for (int i = 1; i < pile.length; i++) {
            pile[i] = t + rs.nextInt(); // last label of worm in pile
            t = pile[i];
        }
        pile[0] = pile[1];
        int m = rs.nextInt();
        for (int i = 0; i < m; i++) {
            System.out.println(nearestAscending(pile, rs.nextInt()));
        }
    }

    public static int nearestAscending(int[] list, int label) {
        int L = 0;                      // lower bound of searching
        int R = list.length - 1;        // upper bound of searching
        int middle;                     // current search candidate
        boolean found = false;
        int location = -1;              // location of item, -1 for failure
        while (L <= R && !found) {
            middle = (L + R) / 2;       // integer division, auto-truncate
            if (middle == 0) { // if middle is on index zero then the worm must be in pile 1
                location = 1;
                found = true;
            } else if (list[middle - 1] < label && list[middle] >= label) { // one pile lower contains worms labeled strictly less than the one we are looking for
                location = middle;      // success!                  // and the current piles highest labeled worm is equal to or less than the one we are looking for
                found = true;
            } else if (label > list[middle]) {
                L = middle + 1;         // look only in R half
            } else {
                R = middle - 1;         // look only in L half
            }
        }
        return location;
    }
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

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

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