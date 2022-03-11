import java.util.Scanner;

public class Problem_118A_String_Task {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String s = input.next().toLowerCase();
        input.close();
        String result = "";

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'A' && s.charAt(i) != 'E' && s.charAt(i) != 'I' && s.charAt(i) != 'O'
                    && s.charAt(i) != 'U' && s.charAt(i) != 'Y') {
                if (s.charAt(i) != 'a' && s.charAt(i) != 'e' && s.charAt(i) != 'i' && s.charAt(i) != 'o'
                        && s.charAt(i) != 'u' && s.charAt(i) != 'y')
                    result += "." + s.charAt(i);
            }
        }
        System.out.println(result);

    }
}
