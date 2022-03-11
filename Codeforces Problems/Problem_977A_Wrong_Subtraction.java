import java.util.Scanner;

public class Problem_977A_Wrong_Subtraction {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt(), k = input.nextInt();

        for (int i = 0; i < k; i++) {
            if (n % 10 == 0)
                n /= 10;
            else 
                n--;
        }
        
        System.out.println(n);
        input.close();

    }

}