import java.util.Scanner;

public class Problem_158B_Taxi {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] groupswith = {0, 0, 0, 0};
        for (int i = 0; i < n; i++) 
            groupswith[input.nextInt()-1]++;
        input.close();

        int numTaxis = groupswith[3];
        int difference;

        // deal with groups of 3
        if (groupswith[2] > 0) {
            difference = groupswith[0] - groupswith[2];
            // if there are more groups of 1
            if (difference > 0) {
            numTaxis += groupswith[2];
            groupswith[0] -= groupswith[2];
            } 
            // if there are more groups of 3 than groups of 1
            else {
                numTaxis += groupswith[2];
                groupswith[0] = 0;
            }
        }

        // Now deal with groups of 2
        if (groupswith[1] > 0) { 
            difference = groupswith[0] - ( 2 * groupswith[1]);
            // if the number of groups of 2 is less than half the number of groups of 1
            if (difference > 0) {
                numTaxis += groupswith[1];
                groupswith[0] -= 2 * groupswith[1]; // multiplied by 2 because each group of 2 is as many as 2 groups of 1
                groupswith[1] = 0;
            }
            // if there are at least half as many groups of 2 as there are groups of 1
            else {
                numTaxis += groupswith[0] / 2;
                groupswith[1] -= groupswith[0] / 2;
                groupswith[0] = groupswith[0] % 2; // if groups of 1 was odd there will still be 1 left over
            } 
        }
        // deal with remaining groups of 2
        if (groupswith[1] > 0) {
            numTaxis += groupswith[1] / 2 + groupswith[1] % 2;
            // if there is an odd number of groups of 2 then add 1 more
        }

        // deal with remaining groups of 1
        if (groupswith[0] > 0) {
            numTaxis += groupswith[0] / 4;
            // if there was no extra group of 2 then add another taxi for the single group of 1
            if (groupswith[0] % 4 > 0 && groupswith[1] % 2 == 0)
                numTaxis++;
        }

      

        System.out.println(numTaxis);
    
    }
}
