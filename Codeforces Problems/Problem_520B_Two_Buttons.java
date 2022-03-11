import java.util.Scanner;

public class Problem_520B_Two_Buttons {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), clicks = 0;
        sc.close();

        while (n != m) {
            clicks++;
            if (m < n || m % 2 == 1) {  // if m (the goal) was less than n (the start), add 1 to get to the start
                m++;                    // if m (the goal) is odd, then it must have been subtracted last, so add 1
            } else 
                m /= 2; // m must be even and greater than n, which means it must have been multiplied by 2 last, so divide
        }

        System.out.println(clicks);
    }
}
