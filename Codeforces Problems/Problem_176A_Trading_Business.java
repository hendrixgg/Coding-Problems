import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;

public class Problem_176A_Trading_Business {
    public static void main(String[] args) throws IOException {

        Reader rs = new Reader();

        int nPlanets = rs.nextInt(), mTypes = rs.nextInt();

        int CAP = Integer.parseInt(rs.readLine().trim());

        int[][][] planetItems = new int[nPlanets][mTypes][3]; // [planet index][item type][0=buy,1=sell,2=qty]

        for (int p = 0; p < nPlanets; p++) {
            rs.nextLine(); // don't care about string
            for (int i = 0; i < mTypes; i++) {
                planetItems[p][i][0] = rs.nextInt(); // cost to buy
                planetItems[p][i][1] = rs.nextInt(); // sell value
                planetItems[p][i][2] = Integer.parseInt(rs.readLine().trim()); // quantity
            }
        }

        int MaxProfit = 0;
        int[][] item = new int[mTypes][2]; // arary which stores the profit of buying and selling an item and the
                                           // qantity

        // for each planet pair
        for (int i = 0; i < nPlanets; i++) {
            for (int j = 0; j < nPlanets; j++) {
                if (i != j) { // don't compare a planet with itself
                    for (int k = 0; k < mTypes; k++) {
                        int[] buy = planetItems[i][k]; // item to buy from the ith planet
                        int[] sell = planetItems[j][k]; // and sell to the jth planet
                        item[k][0] = buy_sell(buy, sell); // value per buy/sell
                        item[k][1] = (item[k][0] < 0) ? 0 : buy[2]; // quantity of item // and do not want to allow
                                                                    // negatives
                    }
                    sortbyColumn(item, 0);// sort the items by their gained values (first column)
                                          // in descending order***

                    int qty = 0, planetI = 0; // counts the number of items bought
                    // iterate from greatest to least
                    for (int k = 0; k < item.length && qty < CAP; k++) { // for each item's profit // and while the ship
                                                                         // has room
                        for (int q = 0; q < item[k][1] && qty < CAP; q++) {// for the quantity of that item
                            planetI += item[k][0]; // add profit
                            qty++; // increment items in ship
                        }
                    }
                    MaxProfit = Math.max(MaxProfit, planetI); // store the profit if it was a maximum
                }
            }
        }

        System.out.println(MaxProfit);

    }

    public static int buy_sell(int[] buy, int[] sell) {
        return sell[1] - buy[0]; // sale price minus the purchase price
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
                if (entry1[col] < entry2[col])
                    return 1;
                else
                    return -1;
            }
        }); // End of function call sort().
    }

    /**
     * This is a Fast input reader that can take input from files and System.in.
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
         * Read data froma file.
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
         * newline character ("\n") is found.
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