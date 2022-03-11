import java.util.Scanner;

public class Problem_4A_Watermelon {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int w = input.nextInt();
        boolean answer = false;
        for(int i = 2; i < w; i += 2) {
            if((w-i) % 2 == 0) {
                answer = true;
            }
        }
        if(answer) {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
        input.close();
    }

}