import java.util.Scanner;

public class Problem_363B_Fence {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        sc.close();
        long currH = 0, minH_index = 1;
        for (int i = 0; i < k; i++) // find starting value (sum of first k heights)
            currH += h[i];
            long minH_val = currH; // get a minimum value to compare to
        for (int i = 1; i <= n - k; i++) { // find best value
            currH -= h[i-1]; // subtract the earliest height
            currH += h[i + k - 1]; // add the new height
            if (currH < minH_val) {
                minH_index = i + 1; // plus 1 because we are calling index 0 the first height
                minH_val = currH;
            }
        }
    
        System.out.println(minH_index);
    }
}
