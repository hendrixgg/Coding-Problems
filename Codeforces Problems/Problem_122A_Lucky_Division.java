import java.util.Scanner;

public class Problem_122A_Lucky_Division {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.close();
        int[] lucky = {4, 7, 44, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
        boolean almostLucky = false;
        for (int i = 0; i < lucky.length; i++) {
            if (n % lucky[i] == 0) {
                almostLucky = true;
                break;
            }
        }

        if (almostLucky)
            System.out.println("YES");
        else
            System.out.println("NO");
    }    
}
