import java.util.Scanner;

public class Problem_479A_Expression {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt(), d, answer = 0; // d is the number to use if i choose to use brackets
        input.close();

        if (a == 1 && c == 1)
            answer = a + b + c;
        else if (a == 1) {
            d = a + b;
            answer = d * c;
        } else if (c == 1) {
            d = b + c;
            answer = a * d;
        } else if (b == 1) {
            d = (a <= c) ? a + b : b + c;
            answer = (a <= c) ? d * c : a * d;
        } else 
            answer = a * b * c;

        System.out.println(answer);

    
    }
}
