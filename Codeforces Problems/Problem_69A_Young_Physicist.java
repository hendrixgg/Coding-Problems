import java.util.Scanner;

public class Problem_69A_Young_Physicist {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] vectors = new int[3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < vectors.length; j++) 
                vectors[j] += input.nextInt();
        }
        input.close();

        if (vectors[0] == 0 && vectors[1] == 0 && vectors[2] == 0)
            System.out.println("YES");
        else
            System.out.println("NO");
    
    }
}
