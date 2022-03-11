import java.util.Scanner;

public class Problem_25A_IQ_Test {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int num, numEvens = 0, lastEven = 0, lastOdd = 0;
        for (int i = 1; i <= n; i++) {
            num = input.nextInt();
            if (num % 2 == 0) {
                numEvens++;
                lastEven = i;
            } else
                lastOdd = i;
        }

        if (numEvens == n - 1)
            System.out.println(lastOdd);
        else    
            System.out.println(lastEven);
        
        input.close();
    
    }
}
