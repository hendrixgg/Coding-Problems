import java.util.Scanner;

/**
 * <h4>Input</h4>
 * <p>
 * The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) —
 * the number of games played.
 * </p>
 * <p>
 * The second line contains a string s, consisting of n uppercase English
 * letters 'A' and 'D' — the outcome of each of the games. The i-th character of
 * the string is equal to 'A' if the Anton won the i-th game and 'D' if Danik
 * won the i-th game.
 * </p>
 * <h4>Output</h4>
 * <p>
 * If Anton won more games than Danik, print "Anton" (without quotes) in the
 * only line of the output.
 * </p>
 * <p>
 * If Danik won more games than Anton, print "Danik" (without quotes) in the
 * only line of the output.
 * </p>
 * <p>
 * If Anton and Danik won the same number of games, print "Friendship" (without
 * quotes).
 * </p>
 */
public class Problem_734A_Anton_and_Danik {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int games = input.nextInt();
        String results = input.next();
        input.close();
        int DanikWins = 0;

        for (int i = 0; i < games; i++) {
            if (results.charAt(i) == 'D')
                DanikWins++;
        }

        if (games % 2 == 0 && DanikWins == games / 2)
            System.out.println("Friendship");
        else if (DanikWins > games / 2)
            System.out.println("Danik");
        else
            System.out.println("Anton");

    }
}
