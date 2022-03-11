import java.util.Scanner;

public class Problem_230A_Dragon {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int playerStrength = input.nextInt(), numDragons = input.nextInt();
        int[] targetDragons = new int[numDragons + 1];// last index in the number of killiable dragons
        int[][] dragonStats = new int[numDragons][3]; // first column is the dragon strength,
                                                      // second column is bonus strength for defeating it
                                                      // third column is 0 when alive, 1 when dead
        for (int i = 0; i < dragonStats.length; i++) {
            dragonStats[i][0] = input.nextInt();
            dragonStats[i][1] = input.nextInt();
            if (dragonStats[i][0] < playerStrength) {
                targetDragons[targetDragons.length - 1]++;
                targetDragons[targetDragons[targetDragons.length - 1] - 1] = i;
            }
        }
        input.close();

        while (numDragons > 0 && targetDragons[targetDragons.length - 1] > 0) {
            for (int i = 0; i < targetDragons[targetDragons.length - 1]; i++) {
                dragonStats[targetDragons[i]][2] = 1; // kill dragon
                playerStrength += dragonStats[targetDragons[i]][1]; // increase player strength
                numDragons--; // decrement remaining dragons
            }
            targetDragons = findTargets(playerStrength, dragonStats);
        }

        if (numDragons == 0)
            System.out.println("YES");
        else 
        System.out.println("NO");

    }

    static int[] findTargets(int strength, int[][] dragonStats) {
        int[] targetDragons = new int[dragonStats.length + 1];
        for (int i = 0; i < dragonStats.length; i++) {
            if (dragonStats[i][0] < strength && dragonStats[i][2] != 1) {
                targetDragons[targetDragons[targetDragons.length - 1]] = i;
                targetDragons[targetDragons.length - 1]++;
            }
        }
        return targetDragons;
    }
}
