package src;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Write a function hanoi(n, start, end) that outputs sequence of steps to move
 * n disks from the start rod to the end rod.
 * 
 * Constraints: (1 <= start, end <= 3), (start != end), (n >= 1)
 * 
 * 1. Smallest possible input: hanoi(1, start, end)
 * 
 * 2. Relate the nth case to the n-1th case:
 * 
 * For hanoi of n discs, first move n-1 discs to the other rod. Then, move the
 * nth disc to the end rod. Finally move the n-1 discs from the other rod to the
 * end rod.
 * 
 * Recurrence relation for number of moves: hanoi(n) = hanoi(n-1) + 1 + hanoi(n-1)
 * 
 * Final realtion: hanoi(1) = 1; hanoi(n) = 2 * hanoi(n-1) + 1;
 * 
 * This turns out to be hanoi(n) = 2^n - 1
 * 
 * 
 * 
 * 
 */
public class Number_Four {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        System.out.println("How many discs are in your tower of hanoi?");
        int n = promptForNumber(sc);
        sc.close();
        
        BigInteger moves = hanoi(n);
        // BigInteger moves = hanoiPrint(n, 1, 3, BigInteger.valueOf(0));

        System.out.printf("Towers of hanoi with %d discs took %,d moves.", n, moves);
    }

    /**
     * Returns the number of moves required to complete the tower of hanoi.
     * @param n
     * @param start
     * @param end
     * @param total
     * @return
     */
    public static BigInteger hanoi(int n) {
        // based off the recurrence relation: hanoi(1) = 1; hanoi(n) = 2 * hanoi(n-1) + 1;
        // this relation turns out to be: hanoi(n) = 2^n - 1
        BigInteger moves = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            moves = moves.multiply(BigInteger.TWO);
        }
        return moves.subtract(BigInteger.ONE);
    }

    /**
     * Returns the number of moves required to complete the tower of hanoi whiile
     * printing all of the moves.
     * 
     * @param n
     * @param start
     * @param end
     * @param total
     * @return
     */
    public static BigInteger hanoiPrint(int n, int start, int end, BigInteger total) {
        // move only one disc (BASE CASE)
        if (n == 1) {
            print_move(start, end);
            total = total.add(BigInteger.ONE);
        } else {
            // the other rod will always be 6 - (start + end)
            int other = 6 - (start + end);

            // move all smaller discs to the other rod
            total = hanoiPrint(n-1, start, other, total);

            // move the biggest disc to the end rod
            print_move(start, end);
            total = total.add(BigInteger.ONE);

            // move the rest of the discs to the end rod
            total = hanoiPrint(n - 1, other, end, total);
        }
        return total;

    }

    public static void print_move(int start, int end) {
        System.out.printf("%d => %d%n", start, end);
    }

    /**
     * promptForNumber - int
     * 
     * @param in a Scanner to read integer values from
     * @return an integer value read from the Scanner
     */
    public static int promptForNumber(Scanner in) {
        int value = 0;
        boolean done = false;
        while (!done) {
            if (in.hasNextInt()) {
                value = in.nextInt();
                in.nextLine(); // Move to the next line
                done = true;
            } else {
                System.out.println("ERROR!  Input not an integer!");
                in.nextLine(); // clear input that is not an integer
            }
        }
        return value;
    }
    
}
