import java.util.Scanner;

public class Problem_451A_Game_With_Sticks {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        sc.close();

        String A = "Akshat", M = "Malvika";

        if (Math.min(n, m) % 2 == 0)
            System.out.println(M);
        else 
            System.out.println(A);
    
    }
}
