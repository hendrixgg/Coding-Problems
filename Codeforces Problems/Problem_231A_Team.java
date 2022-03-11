import java.util.Scanner;

public class Problem_231A_Team {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[][] problem = new int[n][3];
        int[] count = new int[n];
        int problems = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < 3; col++) {
                problem[row][col] = input.nextInt();
                if(problem[row][col] == 1)
                count[row]++;
            }
            if(count[row] >= 2)
            problems++;
        }

        System.out.println(problems);

        input.close();
    }

}
