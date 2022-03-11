import java.util.Scanner;

/**
 * @see this is for if you want larger sizes to work, use <a href =
 *      "https://stackoverflow.com/questions/6563258/how-to-initialise-biginteger-after-creating-instantces-constructor-cant-be-cal">BigInteger</a>.
 */
public class Grid_Traveler_Problem {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(), n = sc.nextInt();
        sc.close();

        // max size for this is a 34 by 34 grid for long values
        System.out.println(gridTraveler1(m, n));

        System.out.println(gridTraveler2(m, n, new long[Math.max(m, n) + 1][Math.max(m, n) + 1]));

        System.out.println(gridTravelerCombo(m, n)); // <--------------- WAYYYYY FASTER (about 4-4.5 times faster)
    }

    /**
     * Uses Tabulation from the end point to the start.
     * @param m
     * @param n
     * @return
     */
    public static long gridTraveler1(int m, int n) {
        long[][] grid = new long[m + 1][n + 1]; // m is the height of the grid, n is the length of the grid
        /**
         * Want to start at the bottom right (grid[m-1][n-1]) and set this spot equal to
         * 1 since there is only one way to stay where you are and that is to move to
         * the position you are on.
         */

        /**
         * Then, you want to iterate one row at a time, from right to left assigning the
         * sum of the 2 below and right positions to the current position.
         * 
         * This looks like: grid[i][j] = grid[i + 1][j] + grid[i][j + 1]
         * 
         * This is to be done up until grid[0][0] is finished.
         */

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--)
                grid[i][j] = (i == m - 1 && j == n - 1) ? 1 : grid[i + 1][j] + grid[i][j + 1];
        }

        return grid[0][0];
    }

    /**
     * Uses memoization and recursion.
     * @param m
     * @param n
     * @param memo
     * @return
     */
    public static long gridTraveler2(int m, int n, long[][] memo) {
        /**
         * Base cases would be: 1. whenever m or n is < 1. resulting in 0. 2. whenever m
         * or n is == 1. resulting in 1. 3. Are the arguments in the memo?
         */
        if (memo[m][n] != 0)
            return memo[m][n];
        if (memo[n][m] != 0)
            return memo[n][m];
        if (m < 1 || n < 1)
            return 0;
        if (m == 1 || n == 1)
            return 1;

        memo[m][n] = gridTraveler2(m - 1, n, memo) + gridTraveler2(m, n - 1, memo);
        return memo[m][n];
    }

    public static long gridTravelerCombo(int m, int n) {
        return choose((m + n - 2), Math.min(m, n) - 1); // take min so smaller number in factorial
    }

    /**
     * Calculates n choose k. <br>
     * </br>
     * First it calculates n! / (n-k)! by the for loop but in a simplified way. <br>
     * </br>
     * ex: n*(n-1)*(n-2)*...*(n-k)) <br>
     * </br>
     * Then it divides (n! / (n - k)!) by k! and returns the result.
     * 
     * @param n
     * @param k
     * @return n! / (k! * (n-k)!)
     */
    public static long choose(long n, long k) {
        // 5 choose >5 is 0 since cant choose 6 from only 5
        if (n < k)
            return 0;
        if (k == 0 || n == k)
            return 1L;

        long ans = 1;
        long[] j = new long[(int) k];
        int l = 0;

        for (int i = 0; i < j.length; i++)
            j[i] = i + 1;

        for (long i = 0; i < k; i++) {
            ans *= (n - i);
            // divides by the factors of k! when it can so that ans doesn't overflow long
            // max val
            while (l < j.length && ans % j[l] == 0) {
                ans /= j[l];
                j[l] = 1;
                l++;
            }
        }

        return ans;
    }
}
