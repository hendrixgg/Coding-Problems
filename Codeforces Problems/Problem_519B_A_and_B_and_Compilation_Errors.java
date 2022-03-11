import java.util.Arrays;
import java.util.Scanner;

public class Problem_519B_A_and_B_and_Compilation_Errors {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), e1 = 0, e2 = 0;
        int[] a = new int[n], b = new int[n - 1], c = new int[n - 2];

        for (int i = 0; i < a.length; i++)
            a[i] = input.nextInt();
        Arrays.sort(a);

        for (int i = 0; i < b.length; i++) 
            b[i] = input.nextInt();
        Arrays.sort(b);

        for (int i = 0; i < c.length; i++)
            c[i] = input.nextInt();
        Arrays.sort(c);

        input.close();
        
        for (int i = 0; i < b.length && (e1 == 0 || e2 == 0); i++) {
            if (e1 == 0)
                e1 = (a[i] - b[i] != 0) ? a[i] : 0;
            if (e2 == 0 && i < c.length)
                e2 = (b[i] - c[i] != 0) ? b[i] : 0;
        }
        // if the error fixed was the highest number
        e1 = (e1 == 0) ? a[n-1] : e1;
        e2 = (e2 == 0) ? b[n-2] : e2;
        System.out.println(e1 + "\n" + e2);

    
    }
}
