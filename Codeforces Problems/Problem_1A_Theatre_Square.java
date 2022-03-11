import java.util.Scanner;

public class Problem_1A_Theatre_Square {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), m = input.nextInt(), a = input.nextInt();
        input.close();

        double stonesAlongN = Math.ceil((n * 1.00)/(a * 1.00));
        double stonesAlongM = Math.ceil((m * 1.00)/(a * 1.00));

        // needs to be type long because (1<= n,m,a <= 10^9)
        // if a is somthing not that large and n and m are close to 10^9 then int will not work
        // int caps out at 2147483647
        long totalStones = (long) (stonesAlongN * stonesAlongM);

        System.out.println(totalStones);
    
    }
}
