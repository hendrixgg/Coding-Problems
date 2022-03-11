import java.util.Scanner;

/**
 * Solved using a dynamic programming with memoization.
 * 
 * The memo array stores prvious fibonacci numbers so they can be recalled
 * without re-calulating.
 */
public class Fibinnaci_Problem {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        System.out.println(fibMemo(n, new long[n + 1]));
        System.out.println(fibTab(n));
    }

    /**
     * Using Memoization.
     * @param n
     * @param memo
     * @return the nth fibonacci number.
     */
    public static long fibMemo(int n, long[] memo) {
        if (n < 1)
            return 0L;
        if (n <= 2) // first two numbers of the sequence are 1
            return 1L;

        if (memo[n] == 0) // if number not calculated yet
            memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);

        return memo[(int) (n)];
        
    }

    /**
     * Using Tabulation.
     * @param n
     * @return
     */
    public static long fibTab(int n) {
        long[] table = new long[n + 2];
        table[1] = 1;
        for (int i = 0; i < n; i++) {
            table[i + 1] += table[i];
            table[i + 2] += table[i];
        }
        return table[n];
    }
}