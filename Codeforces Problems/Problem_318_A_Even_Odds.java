import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Problem_318_A_Even_Odds {
        public static void main(String[] args) throws IOException {
    
            Reader rs = new Reader();
            // firstly all odd integers from 1 to n (in ascending order), then all even
            // integers from 1 to n (also in ascending order).
            long n = rs.nextLong(), k = rs.nextLong(), ans = 0;
            // n is even
            if (n % 2 == 0) { 
                if (k > n/2) {              // if referring to even part
                    ans = 2 * (k - n / 2);
                } else                      // if referring to odd part
                    ans = 2*k - 1;
            } 
            // n is odd
            else { 
                if (k <= n / 2 + 1) {       // odd part of the sequence
                    ans = 2*k - 1;
                } else {                    // even part of sequences
                    ans = 2 * (k - n / 2 - 1);
                }
            }
            System.out.println(ans);
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
