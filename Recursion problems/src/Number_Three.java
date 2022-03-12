package src;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Write a function that counts the number of ways that you can partition n
 * objects using parts up to m (assuming m >= 0).
 * 
 * Step 1: What is the simpleest input?
 * 
 * count_partitions(0, 0) => 1
 * count_partitions(0, 1) => 1
 * 
 * ***count_partitions(n, m) => 1, if n == 0 ***
 * 
 * count_partitions(1, 0) => 0
 * count_partitions(2, 0) => 0
 * 
 * ***count_partitions(n, m) => 0, if m == 0 && n > 0 ***
 * 
 * Step 2: Visualize examples in notebook.
 * 
 * 
 * Step 3: generalize the pattern.
 * 
 * count_partitions(n, m) = count_partitions(n - m, m) + count_partitions(n, m - 1)
 * 
 * Although if n is less than m then n - m < 0; so another base case must be made.
 * 
 * *** count_partitions(n, m) => 0 if n < 0 ***
 * 
 */
public class Number_Three {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int numObjects = sc.nextInt(), largestGroup = sc.nextInt();
        sc.close();

        System.out.println();

        // System.out.printf("Simple Recursion:           %,d%n%n",count_partitions(numObjects, largestGroup)); // very slow

        // these run in O(n*m) time and space compexity
        System.out.printf("Recursion with memoization: %,d%n%n",count_partitionsM(numObjects, largestGroup)); 

        System.out.printf("Tabulation:                 %,d%n%n",count_partitionsT(numObjects, largestGroup));

        // if you are asked to do many test cases. it would make sense to store all test
        // cases in an array and remember the largest test case.

        // In this case, Tabulation would have to be used to populte the entire 2d table
        // and then you would be able to just return values for each test case.
    
    }

    public static BigInteger count_partitions(int n, int m) {
        if (n == 0)
            return BigInteger.valueOf(1);
        if (m == 0 || n < 0)
            return BigInteger.valueOf(0);
        else
            return count_partitions(n - m, m).add(count_partitions(n, m - 1));
    }

    /**
     * This algorithm runs in O(n*m) time and takes up O(n*m) space. This can be
     * visualized by uncommenting the method that prints the memo array.
     * 
     * @param n
     * @param m
     * @return
     */
    public static BigInteger count_partitionsM(int n, int m) {
        BigInteger[][] memo = new BigInteger[n + 1][m + 1];
        BigInteger ans = count_partitionsM(n, m, memo);
        printArray2d(memo);
        return ans;
    }

    /**
     * This algorithm runs in O(n*m) time and takes up O(n*m) space.
     * @param n
     * @param m
     * @return
     */
    public static BigInteger count_partitionsM(int n, int m, BigInteger[][] memo) {
        if (n == 0)
            return BigInteger.valueOf(1);
        if (m == 0 || n < 0)
            return BigInteger.valueOf(0);
        if (memo[n][m] != null && memo[n][m].equals(BigInteger.valueOf(0)) == false) 
            return memo[n][m];

        memo[n][m] = count_partitionsM(n - m, m, memo).add(count_partitionsM(n, m - 1, memo));
        return memo[n][m];
    }

    /**
     * This algorithm runs in O(n*m) time and takes up O(n*m) space. This can be
     * visualized by uncommenting the method that prints the table array.
     * 
     * @param n
     * @param m
     * @return
     */
    public static BigInteger count_partitionsT(int n, int m) {
        
        BigInteger[][] table = new BigInteger[n + 1][m + 1];

        // initial values
        // top two rows filled with 1's
        // this is for n == 1 or n == 0 
        for (int i = 0; i <= m; i++) {
            table[0][i] = BigInteger.valueOf(1);
            table[1][i] = BigInteger.valueOf(1);
        }
        // 0th column from row 2 down filled with 0's
        // 1st column from row 2 down filled with 1's
        for (int i = 2; i <= n; i++) {
            table[i][0] = BigInteger.valueOf(0);
            table[i][1] = BigInteger.valueOf(1);
        }

        // recurrence relation: table[n][m] = table[n][m-1] + table[n-m][m]
        // if n - m < 0 then give just table[n][m-1]

        for (int N = 2; N <= n; N++) {
            for (int M = 2; M <= n - N || N == n; M++) { // change boolean expression to just (M <= m) to generate every value
                if (M > m)
                    break;
                table[N][M] = (N - M < 0) ? table[N][M - 1] : table[N][M - 1].add(table[N - M][M]);
                // printArray2d(table);
            }
        }

        // this prints the finished table of numbers
        // printArray2d(table);

        return table[n][m];
    }

    public static void printArray2d(BigInteger[][] arr) {
        // this prints the finished table of numbers
        System.out.println();
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] == null)
                    System.out.printf("%4d ", 0);
                else
                    System.out.printf("%4d ", arr[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }


}
