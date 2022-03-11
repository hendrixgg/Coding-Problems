import java.util.Scanner;

public class Problem_270A_Fancy_Fence {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        boolean[] tests = new boolean[input.nextInt()];
        for (int i = 0; i < tests.length; i++) {
            int extAngle = 180 - input.nextInt(); // if 180 - angle (exterior angle) % 360 = 0, a regular polygon can be built
            tests[i] = (360 % extAngle == 0) ? true : false;
        }
        for (int i = 0; i < tests.length; i++) {
            String ans = tests[i] ? "YES" : "NO";
            System.out.println(ans);
        }
        input.close();
    
    }
}
