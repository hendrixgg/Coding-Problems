import java.util.Scanner;

/**
 * <h4>Input</h4>
 * <p>
 * The first line contains word s, the second line contains word t. The words
 * consist of lowercase Latin letters. The input data do not consist unnecessary
 * spaces. The words are not empty and their lengths do not exceed 100 symbols.
 * </p>
 * <h4>Output</h4>
 * <p>
 * If the word t is a word s, written reversely, print YES, otherwise print NO.
 * </p>
 */
public class Problem_41A_Tranlation {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String s = input.nextLine(), t = input.nextLine();
        input.close();
        boolean reversely = false;
        if (s.length() == t.length()) {
            reversely = true;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != t.charAt(t.length()-1-i))
                    reversely = false;
            }
        }
        if (reversely)
            System.out.println("YES");
        else
            System.out.println("NO");

    }
}
