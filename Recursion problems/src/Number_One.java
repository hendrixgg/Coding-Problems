package src;
import java.util.Scanner;

/**
 * Write a funtion that given an input n sums all nonnegative integers up to n.
 * <br>
 * </br>
 * How would you solve this recursively?
 */
public class Number_One {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();

        System.out.printf("The sum of the first %d natural numbers is %d%n", n, sumUpToN(n));
        // check with formula
        int check = n * (n + 1) / 2;
        System.out.printf("Check: %d", check);
    
    }

    /**
     * sum(k) = sum(k -1) + k
     * 
     * Highest n value possible : 22167
     * @param n
     * @return
     */
    static int sumUpToN(int n) {
        if (n <= 0)
            return 0; // base case
        else
            return sumUpToN(n - 1) + n;
    }
}
