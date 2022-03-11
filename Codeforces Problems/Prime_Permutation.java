import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
 
/**
 * https://codeforces.com/contest/123/problem/A
 */
public class Prime_Permutation {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        String s = rs.readLine(1005).trim();
        int length = s.length();
        int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
                101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331,
                337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457,
                461, 463, 467, 479, 487, 491, 499, 503 };
 
        int unnecessary_primes = 1;
        for (int p : primes) {
            if (2 * p > length)
                unnecessary_primes++;
        }
        int prs = primes.length - unnecessary_primes;
        // taking character frequency
        int freq[] = new int['z' + 1];
        for (int i = 0; i < length; i++){
            freq[s.charAt(i)]++;
        }
        byte max = 'a';
        // finding the most common character
        for (byte i = 'b'; i <= 'z'; i++) {
            if (freq[i] > freq[max])
                max = i;
        }
        // find indicies where common character is needed
        boolean same[] = new boolean[length];
        int same_req = 0;
        ArrayList<Integer> q = new ArrayList<Integer>();
        for (int i = 0; i <= prs; i++) { // for each prime <= |s|/2
            for (int j = primes[i]; j <= length ; j+=primes[i]) {
                if (!same[j-1]) {
                    same[j-1] = true;
                    same_req++;
                    q.add(j-1);
                }
            }
        }
        
 
        if (freq[max] < same_req)
            System.out.println("NO");
        else { // build a valid string and print yes
            byte result[] = new byte[length];
            for (int i : q) {
                result[i] = max;
                freq[max]--;
            }
            byte l = 0;
            for (int i = 0; i < length; i++) {
                if (result[i] != 0)
                    continue;
                while (freq[l] == 0)
                    l++;
                result[i] = l;
                freq[l]--;
            }
            System.out.println("YES\n" + new String(result));
        }
        
 
 
 
 
        rs.close();
    }
    /*
        xxxyxxx
         ^^^ ^
 
    */
    
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
         * @param file_path
         * @throws IOException
         */
        public Reader(String file_path) throws IOException {
            din = new DataInputStream(new FileInputStream(file_path));
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