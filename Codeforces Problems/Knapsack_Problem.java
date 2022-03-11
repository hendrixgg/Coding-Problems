import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * First line contains the number of items available and the capacity of the knapsack.
 * Second line contains the weight of each item.
 * Third line contains the value of each item.
 * 
 * test cases at the bottom
 */
public class Knapsack_Problem {
    public static void main(String[] args) throws Exception {
    
        Reader rs = new Reader();
        int n = rs.nextInt(), cap = rs.nextInt(); // number items available, capacity of knapsack
        int minWeight = 0;
        int vals[] = new int[n+1], w[] = new int[n+1];
        for (int i = 1; i <= n; i++) {
            w[i] = rs.nextInt(); // read the weight of the item
            minWeight =  Math.min(minWeight, w[i]);
        }
        for (int i = 1; i <= n; i++) {
            vals[i] = rs.nextInt(); // read the value of the item
        }
        if (minWeight > cap) {
            System.out.println(0);
        }
        int dp[][] = new int[n+1][cap+1];
        System.out.println("\n" + knapsack_recur(n, cap, vals, w, dp)); // faster for worst case
        // printGrid(dp);
        System.out.println("\n" + knapsack_iter(n, cap, vals, w, dp = new int[n+1][cap+1]));
        // printGrid(dp);
        rs.close();
    }

    // faster 
    static int knapsack_recur(int n, int cap, int val[], int wt[], int dp[][]) {
        if (n == 0 || cap == 0) // return 0 if you cannot add more items
            return 0;
        if (dp[n][cap] != 0)
            return dp[n][cap];

        if (wt[n] > cap) // skip over item if it is too heavy
            dp[n][cap] = knapsack_recur(n-1, cap, val, wt, dp);
        else {
            int take = val[n] + knapsack_recur(n-1, cap-wt[n], val, wt, dp);
            int leave = knapsack_recur(n-1, cap, val, wt, dp);   
            dp[n][cap] = Math.max(take, leave);
        }
        return dp[n][cap];
    }

    // slower since all positions are checked
    static int knapsack_iter(int n, int cap, int val[], int wt[], int dp[][]) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= cap; j++) {
                if (wt[i] > j) // if we cannot include the item
                    dp[i][j] = dp[i-1][j]; // equivalent to line 43
                else                  // below line is equivalent to lines 45, 46, 47
                    dp[i][j] = Math.max(dp[i-1][j], val[i] + dp[i-1][j - wt[i]]); // either do not includ the item
            }                                                                     // or include the item and the dp[without the item][with reduced weight from taking the item]
        }
        return dp[n][cap];
    }

    static void printGrid(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                System.out.printf("%4d", grid[i][j]);
            }
            System.out.println("\n");
        }
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

/*

Test cases:

in:
5 10
1 2 4 2 5
5 3 5 3 2

out: 16


in:
24 6404180
382745
799601
909247
729069
467902
44328
34610
698150
823460
903959
853665
551830
610856
670702
488960
951111
323046
446298
931161
31385
496951
264724
224916
169684

825594
1677009
1676628
1523970
943972
97426
69666
1296457
1679693
1902996
1844992
1049289
1252836
1319836
953277
2067538
675367
853655
1826027
65731
901489
577243
466257
369261

out: 13549094



in: 
3 50
10 20 30
60 100 120

out: 220


in: 

10 165
23 31 29 44 53 38 63 85 89 82
92 57 49 68 60 43 67 84 87 72

out: 309
*/
