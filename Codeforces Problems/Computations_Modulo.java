import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Computations_Modulo {
    public static void main(String[] args) throws IOException {

        // Reader rs = new Reader();
        // int MOD = rs.nextInt();
        System.out.println();

        // if you are doing mod 2^32 the you can just do this:
        /*
            int ans = (result of some operation/function);
            long answer = (ans % MOD + MOD) % MOD); // where MOD = 1l << 32;
        */
    }

    static int subtractMOD(int a, int b, int mod) {
        int ans = (a - b) % mod;
        if (ans < 0)
            ans += mod;
        return ans;
    }

    static int multiplyMOD(int a, int b, int mod) {
        return ((a % mod) * (b % mod)) % mod;
    }

    /**
     * ONLY FOR PRIME MODULO.
     * 
     * @param a
     * @param b
     * @return
     */
    static int divideMOD(int a, int b, int Pmod) {
        // Pmod must be prime
        return multiplyMOD(a, fastpowMOD(b, Pmod - 2, Pmod), Pmod);
    }

    static int fastpowMOD(int b, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * b) % mod;
            b = (b*b) % mod;
            exp /= 2;
        }
        return result;
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
