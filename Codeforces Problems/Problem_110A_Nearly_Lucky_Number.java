import java.util.Scanner;

/**
 * <h4>Input</h4>
 * <p>
 * The only line contains an integer n (1 ≤ n ≤ 10^18).
 * </p>
 * 
 * <h4>Output</h4>
 * <p>
 * Print on the single line "YES" if n is a nearly lucky number. Otherwise,
 * print "NO" (without the quotes).
 * </p>
 */
public class Problem_110A_Nearly_Lucky_Number {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        String number = input.next();
        int numberInt = 0;
        input.close();
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) == '4' || number.charAt(i) == '7')
                numberInt++;
        }
        // only options are 4 or 7 occurrences of 4 or 7 
        // because there are at most 19 digits in the number String
        if (numberInt == 4 || numberInt == 7)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
