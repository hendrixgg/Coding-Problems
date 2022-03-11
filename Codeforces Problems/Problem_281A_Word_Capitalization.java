import java.util.Scanner;

public class Problem_281A_Word_Capitalization {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String word = input.next();
        String s1 = word.substring(0, 1).toUpperCase();
        String s2 = word.substring(1, word.length());
        word = s1 + s2;
        System.out.println(word);

        input.close();

    }

}