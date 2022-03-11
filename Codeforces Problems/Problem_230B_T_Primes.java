import java.util.Scanner;

/**
 * A number is only t-prime if it has exactly 3 distinct factors. The only
 * numbers with 3 distinct factors are prime numbers squared. <br>
 * </br>
 * This solution uses what is called the Sieve of Eratosthenes to create an
 * array that has a 0 at the index of a prime number and a 1 at the index of a
 * composite number.
 * 
 * @see https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
public class Problem_230B_T_Primes {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), limit = 1000000;
        long num;
        int[] isPrime = primeArray(limit);

        for (int i = 0; i < n; i++) {
            num = sc.nextLong();
            if (num == 4) {
                System.out.println("YES");
            } else if (num % 2 == 0) {
                System.out.println("NO");
            } else if (isPerfectSquare(num) && isPrime[(int) Math.sqrt(num)] == 0) {
                System.out.println("YES");
            } else
                System.out.println("NO");
        }
        sc.close();

    }

    /**
     * generates an array that contains a 0 at every prime index.
     * 
     * @param limit
     * @return
     */
    static int[] primeArray(int limit) {
        int[] primes = new int[limit];
        primes[0] = primes[1] = 1;
        for (int i = 2; i < primes.length; i++) {
            if (primes[(int) i] == 0) {
                for (int j = i * i; j < primes.length; j += i)
                    primes[(int) j] = 1;
            }

        }
        return primes;
    }

    static boolean isPerfectSquare(long n) {
        double sqrt_n = Math.sqrt(n);
        if (sqrt_n == (int) sqrt_n)
            return true;
        return false;
    }
}
