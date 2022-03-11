import java.util.Scanner;

public class Problem_327A_Flipping_Game {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt(), maximum = 0;
        int[] numbers = new int[num];
        for (int i = 0; i < numbers.length; i++) // collect all numbers
            numbers[i] = sc.nextInt();
        sc.close();

        int current;
        for (int j = 0; j < numbers.length; j++) {  // end index (of flipped bits)
            for (int i = 0; i <= j; i++) {          // start index (of flipped bits)
                current = 0;
                // add the regular numbers befor index i
                for (int k = 0; k < i; k++)
                    current += numbers[k];
                // add up all flipped bits in range [i,j]
                for (int k = i; k <= j; k++)
                    current += 1 - numbers[k];
                // add the regular numbers after index j
                for (int k = j + 1; k < numbers.length; k++)
                    current += numbers[k];
                maximum = Math.max(maximum, current); // check if current is new highest
            }
        }
    
        System.out.println(maximum);
    }
}
