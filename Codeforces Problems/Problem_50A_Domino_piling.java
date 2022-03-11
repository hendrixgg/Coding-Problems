import java.util.Scanner;

public class Problem_50A_Domino_piling {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int M = input.nextInt(), N = input.nextInt();
        int size = M*N;

        int total = size/2;

        System.out.println(total);

        input.close();
    }

}
