import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Problem_313B_Ilya_and_Queries {
    public static void main(String[] args) throws IOException {

        Reader sc = new Reader();
        int l = 0, c = 0, cnt = 1;
        int[] dp = new int[100_005];
        c = sc.read(); // first character
        l = c;
        dp[0] = 0; // initial value
        while ((c = sc.read()) != -1) { // reads all charachters as bytes and puts a 1 in the table if the next character is the same
            if (c == '\n')
                break;        
            if (l == c && cnt < dp.length - 1) // if the last character equal the current character
                dp[cnt] = dp[cnt - 1] + 1;
            else
                dp[cnt] = dp[cnt-1];
            l = c;
            cnt++;
        }
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            System.out.println(dp[b-1] - dp[a-1]);
        }
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
    
            /**
             * reads the line with standard length of 64.
             * @return
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
             * reads the line with the specified length.
             * @param length
             * @return
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