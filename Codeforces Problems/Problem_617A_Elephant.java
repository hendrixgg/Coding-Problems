import java.util.Scanner;

public class Problem_617A_Elephant {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        
        int x = input.nextInt();

        if (x % 5 == 0)
            System.out.println(x / 5);

        for (int i = 1; i < 5; i++) {
            if ((x - i) % 5 == 0)
                System.out.println((1 + (x - i) / 5));
        }

        input.close();

    }

}