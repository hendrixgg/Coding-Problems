import java.util.Scanner;

public class Problem_236A_Boy_or_Girl {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String username = input.next();
        boolean[] characterSet = new boolean[26];
        int total = 0;

        for (int i = 0; i < username.length(); i++) {
            characterSet[username.charAt(i)-'a'] = true;
        }
        for (int i = 0; i < characterSet.length; i++) {
            if (characterSet[i] == true)
            total++;
        }
        if (total % 2 == 0) {
            System.out.println("CHAT WITH HER!");
        }else {
            System.out.println("IGNORE HIM!");
        }
        
            input.close();

    }

}