import java.util.Scanner;

public class RECURRENCE_RELATION_Problem_455A_Boredom {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), num, MAX = 100001; // numbers from 0 to 10^5
        long[] count = new long[MAX]; // index 1 is the number of 1's, index 2 is the number of 2's and so on
        long[] points = new long[MAX]; // both need to be long since maximum value is 10^10
        for (int i = 0; i < n; i++) {
            num = sc.nextInt();
            count[num]++;
        }
        sc.close();

        points[0] = 0;
        points[1] = count[1];

        /**
         * There are 2 possible cases for each turn:
         * 
         * Case 1: i (the number) is selected
         * 
         * If i is seleted, then all occurrences of i must be selected to maximize the
         * points. Also elements i - 1 cannot be used since it is adjacent and will be
         * deleted. (do not care about i + 1 since it will be iterating up to that
         * point)
         * 
         * points scored in this case = i * count[i] + points[i - 2]
         * 
         * Case 2: i (the number) is not selected
         * 
         * If you do not select i, then i - 1 must be selected since it the next element
         * over.
         * 
         * points scored in this case = points[i - 1]
         * 
         * Recurrence relation: points[i] = max(i*count[i] + points[i - 2], points[i - 1])
         */
    
        for (int i = 2; i < MAX; i++) {
            points[i] = Math.max(i*count[i] + points[i - 2], points[i - 1]);
        }

        System.out.println(points[MAX - 1]);

    }
}
