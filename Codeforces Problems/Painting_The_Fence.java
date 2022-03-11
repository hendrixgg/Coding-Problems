import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;

/**
 * https://codeforces.com/contest/1132/problem/C
 */
public class Painting_The_Fence {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        int s = rs.nextInt(), p = rs.nextInt();
        int l_r_tmp[][] = new int[p][3];
        int cnt[] = new int[s]; // if the entry is greater than 0 than the sector is paintable
        int total = 0; // total paintable sectors
        int redundant = 0; // number of redundant painters
        int f_t[][] = new int[2][s];
        Arrays.fill(f_t[0], -1);
        for (int i = 0; i < p; i++) {
            l_r_tmp[i][0] = rs.nextInt()-1; // leftmost section
            l_r_tmp[i][1] = rs.nextInt()-1; // rightmost section
            for (int j = l_r_tmp[i][0]; j <= l_r_tmp[i][1]; j++) {
                if (f_t[0][j] == -1)
                    total++; // new paintable sector
                if (l_r_tmp[i][1] > f_t[0][j] || f_t[0][j] == -1)  {
                    f_t[0][j] = l_r_tmp[i][1];
                    f_t[1][j] = 1;
                } else if (l_r_tmp[i][1] == f_t[0][j]) {
                    f_t[1][j]++;
                }
            }
        }
        // find redundant painters
        for (int guy = 0; guy < p; guy++) {
            if (l_r_tmp[guy][1] < f_t[0][l_r_tmp[guy][0]]) {// redundant
                l_r_tmp[guy][2] = 1; // flag as redundant
                redundant++; // number of redundant painters
            } else if (l_r_tmp[guy][1] == f_t[0][l_r_tmp[guy][0]] && f_t[1][l_r_tmp[guy][0]] > 1) {// redundant
                for (int i = l_r_tmp[guy][0]; i <= l_r_tmp[guy][1]; i++) {
                    f_t[1][i]--; // reduce overlap b/c redundant
                }
                l_r_tmp[guy][2] = 1; // flag as redundant
                redundant++; // number of redundant painters
            }
        }
        if (redundant >= 2)
            System.out.println(total);
        else {
            int l[] = new int[p - redundant], r[] = new int[p - redundant];
            int l_r[][] = new int[p-redundant][2]; // for the dp sol
            for (int i = 0, j = 0; i < p - redundant; i++, j++) {
                while (l_r_tmp[j][2] == 1) // if it was redundant
                    j++;
                l[i] = l_r_tmp[j][0]; // I messed up dimensions
                r[i] = l_r_tmp[j][1]; // since I solved redundancies 
                l_r[i] = l_r_tmp[j];  // after original solution
            }
            sol_with_Prefix_Sum(l, r, cnt, s, p - redundant, redundant, total);
            // sol_with_dp(l_r, cnt, s, 2 - redundant); // 2 since we can hire p - 2 of the known painters
        }
        rs.close();
    }

    // Need to learn more about how to make it work
    static void sol_with_dp(int[][] l_r, int[] cnt, int s, int skip) {
        sortbyColumn(l_r, 0);
        // dp[i][skipped] is the maximum number of painted sect if the next sect to paint is i
        // with skipped being the number of skipped painters so far
        int dp[][] = new int[s + 1][skip + 1];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        dp[0][0] = 0;
        // now iterate for each painter
        for (int[] pair : l_r) {
            for (int i = s; i >= 0; i--) {
                int extra = Math.max(0, pair[1] - Math.max(i, pair[0]) + 1);
                for (int skipped = skip; skipped >= 0; skipped--) {
                    if (skipped != skip) {
                        dp[i][skipped + 1] = Math.max(dp[i][skipped + 1], dp[i][skipped]);
                    }
                    // printGrid(dp);
                    dp[Math.max(i, pair[1] + 1)][skipped] = Math.max(dp[Math.max(i, pair[1] + 1)][skipped],
                            dp[i][skipped] + extra);
                    // printGrid(dp);
                }
            }
        }
        int answer = 0;
        for (int i = 0; i <= s; i++) {
            answer = Math.max(answer, dp[i][skip]);
        }
        System.out.println(answer);
    }

    static void sol_with_Prefix_Sum(int l[], int r[], int cnt[], int s, int p, int red, int total) {
        // add 1 for each painter can paint that sector
        for (int i = 0; i < p; i++) {
            for (int j = l[i]; j <= r[i]; j++) {
                cnt[j]++;
            }
        }
        int max = 0;
        for (int i = 0; i < p && max < total; i++) {
            int sub1 = 0;
            // sects that only painter i can paint
            for (int k = l[i]; k <= r[i]; k++) {
                cnt[k]--;
                if (cnt[k] == 0)
                    sub1++;
            }
            if (red == 0) { // don't need to do if one was redundant
                // prefix sum of spots where there are now 1's
                int pre[] = new int[s];
                for (int j = 0; j < cnt.length; j++) {
                    if (cnt[j] == 1)
                        pre[j] = 1;
                }
                for (int j = 1; j < s; j++) {
                    pre[j] += pre[j-1];
                }
                // check other options
                for (int j = 0; j < p; j++) {
                    if (j == i)
                        continue;
                    int sub2 = pre[r[j]] - (l[j] != 0 ? pre[l[j]-1] : 0); // sects that cannot be painted without painters i and j
                    max = Math.max(total - sub1 - sub2, max);
                }
            } else {
                max = Math.max(total - sub1, max);
            }
            for (int k = l[i]; k <= r[i]; k++) { // increase what we subtracted earlier
                cnt[k]++;
            }
        }
        System.out.println(max);
    }

    /**
     * Takes in a 2d array and the column index by which to sort the array.
     * @param arr
     * @param col
     */
    public static void sortbyColumn(int arr[][], int col) {
        
        // Using built-in sort function Arrays.sort
        Arrays.sort(arr, new Comparator<int[]>() {
    
            @Override
            // Compare values according to columns
            public int compare(final int[] entry1, final int[] entry2) {
    
                // To sort in descending order revert
                // the '>' Operator
                if (entry1[col] > entry2[col])
                    return 1;
                else if (entry1[col] == entry2[col]) { // if equal sort based on most area covered to least covered
                    if (entry1[1] == entry2[1])
                        return 0;
                    if (entry1[1] > entry2[1])
                        return 1;
                    else
                        return -1;
                }
                else
                    return -1;
            }
        }); // End of function call sort().
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
