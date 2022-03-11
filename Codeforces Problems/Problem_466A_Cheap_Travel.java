import java.util.Scanner;

public class Problem_466A_Cheap_Travel {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int rides = sc.nextInt(), ridesPer_M = sc.nextInt(), costPer_1 = sc.nextInt(), costPer_M = sc.nextInt();
        sc.close();

        // 0 for M_ride ticket being a better deal, 1 for single ride ticket being
        // better deal or the same
        int betterDeal = (costPer_M / ridesPer_M < costPer_1) ? 0 : 1;
        int totalCost = 0;

        if (betterDeal == 1)
            totalCost = rides * costPer_1;
        else {
            totalCost = (rides / ridesPer_M) * costPer_M; // buy up M ride tickets

            // buy another m ride ticket if it's cheaper than buying 1 ride tickets for the remaining rides
            totalCost += (costPer_M < (rides % ridesPer_M) * costPer_1) ? costPer_M : (rides % ridesPer_M) * costPer_1;
        }

        System.out.println(totalCost);

    }
}