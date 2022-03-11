import java.util.Scanner;

public class Problem_263A_Beutiful_Matrix {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int moves = 0;
        int[][] matrix = new int[5][5];

        for(int row = 0; row < matrix.length; row++) {
            for(int col = 0; col < matrix[row].length; col++) {
                matrix[row][col] = input.nextInt();
                if(matrix[row][col] == 1) {
                    moves = Math.abs((row-2)) + Math.abs((col-2));
                }
            }
        }

        System.out.println(moves);

        input.close();

    }

}
