import java.util.Arrays;
import java.util.Scanner;

public class Problem_492B_Vasya_and_lanterns {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), length = input.nextInt();
        double minR = 0, minDist = 0;
        int[] lanternPos = new int[n];
        for (int i = 0; i < lanternPos.length; i++)
            lanternPos[i] = input.nextInt();
        input.close();

        Arrays.sort(lanternPos);

        if (lanternPos.length == 1)
            minR = Math.max(lanternPos[0], length - lanternPos[0]);
        else if (length == 1)
            minR = 1;
        else {
            for (int i = 0; i < lanternPos.length; i++) {
                if (i == 0) {// on first lantern
                    minDist = Math.max(lanternPos[i], lanternPos[i + 1] - lanternPos[i]);
                    minR = lanternPos[i];
                }
                else if (i != lanternPos.length - 1)
                    minDist = Math.max(minDist, lanternPos[i + 1] - lanternPos[i]);
                // if on last lantern
                if (i == lanternPos.length - 1)
                    minR = Math.max(minR, length - lanternPos[i]);
            }
            minR = Math.max(minR, minDist / 2.000000000000000000);
        }

        System.out.printf("%.10f",minR);
    
    }    
}
