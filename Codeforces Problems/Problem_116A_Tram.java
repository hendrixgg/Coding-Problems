import java.util.Scanner;

public class Problem_116A_Tram {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int numStops = input.nextInt();
        int[][] stop = new int[numStops][2];
        int maxPassengers = 0;
        int currentPassengers = 0;

        for (int i = 0; i < numStops; i++) {
            for (int j = 0; j < 2; j++) {
                stop[i][j] = input.nextInt();
                if (j == 1) {
                currentPassengers += stop[i][j];
                maxPassengers = Math.max(currentPassengers, maxPassengers);
                }else {
                    currentPassengers -= stop[i][j];
                }
            }
        }

        System.out.println(maxPassengers);
            input.close();

    }

}