import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Best_Sum {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        // -------USER INPUT------- //
        // long targetSum = sc.nextLong();
        // int max = sc.nextInt();
        // long[] numbers = new long[max];
        // for (int i = 0; i < numbers.length; i++)
        // numbers[i] = sc.nextInt();
        // -------USER INPUT------- //
        int n = sc.nextInt(); // 0 for memoization, anything else for tabulation
        sc.close();

        // test cases
        if (n == 0) {
            int[] nums1 = { 5, 3, 4, 7 };
            System.out.println(bestSumMemo(7, nums1)); // [7]
            int[] nums2 = { 2, 3, 5 };
            System.out.println(bestSumMemo(8, nums2)); // [3, 5]
            int[] nums3 = { 1, 4, 5 };
            System.out.println(bestSumMemo(8, nums3)); // [4, 4]
            int[] nums4 = { 1, 2, 5, 25 };
            System.out.println(bestSumMemo(100, nums4)); // [25, 25, 25, 25]
        } else {
            int[] nums1 = { 5, 3, 4, 7 };
            System.out.println(Arrays.toString(bestSumTab(7, nums1))); // [7]
            int[] nums2 = { 2, 3, 5 };
            System.out.println(Arrays.toString(bestSumTab(8, nums2))); // [3, 5]
            int[] nums3 = { 1, 4, 5 };
            System.out.println(Arrays.toString(bestSumTab(8, nums3))); // [4, 4]
            int[] nums4 = { 1, 2, 5, 25 };
            System.out.println(Arrays.toString(bestSumTab(100, nums4))); // [25, 25, 25, 25]
        }

    }

    /**
     * let m = targetSum, n = numbers.length <br>
     * </br>
     * Brute Force:<br>
     * </br>
     * Time: O(n^m) branch for every n, m times <br>
     * </br>
     * Space: O(m*m) = O(m^2) (max stack depth = m)*(max length of shortestCombo 
     * Array) <br></br>
     * Memoized: <br></br>
     * Time: O(n*m^2) = O(m * n * m) stack-depth * branches_per_lvl * copying_remainderCombo_to_shortest
     * Space: O(m^2) memo containing m arrays of maximum length m, so m*m or m^2
     * 
     * @param targetSum
     * @param numbers
     * @param memo
     * @return
     */
    public static ArrayList<Integer> bestSumMemo(int targetSum, int[] numbers) {
        ArrayList<Integer>[] memo = new ArrayList[targetSum + 1];
        for (int i = 1; i < memo.length; i++) {
            memo[i] = new ArrayList<Integer>();
        }
        return bestSumMemo(targetSum, numbers, memo);
    }

    /**
     * let m = targetSum, n = numbers.length <br>
     * </br>
     * Brute Force:<br>
     * </br>
     * Time: O(n^m) branch for every n, m times <br>
     * </br>
     * Space: O(m*m) = O(m^2) (max stack depth = m)*(max length of shortestCombo 
     * Array) <br></br>
     * Memoized: <br></br>
     * Time: O(n*m^2) = O(m * n * m) stack-depth * branches_per_lvl * copying_remainderCombo_to_shortest
     * Space: O(m^2) memo containing m arrays of maximum length m, so m*m or m^2
     * 
     * @param targetSum
     * @param numbers
     * @param memo
     * @return
     */
    public static ArrayList<Integer> bestSumMemo(int targetSum, int[] numbers, ArrayList<Integer>[] memo) {
        /**
         * Base cases: 
         * 1. targetSum == 0 --> return empty array 
         * 2. targetSum < 0 --> return null 
         * 3. memo[targetSum] == null --> return null 
         * 4. memo[targetSum] != -1 --> return ArrayList @ memo[targetSum]
         */
        if (targetSum == 0)
            return new ArrayList<Integer>(); // empty array since the sum worked
        if (targetSum < 0)
            return null;
        if (memo[targetSum] == null) // if done and not worked
             return null;
        if (memo[targetSum].size() != 0) // if already done and worked
             return memo[targetSum];

        ArrayList<Integer> shortestCombo = null;

        for (int i = 0; i < numbers.length; i++) {
            int remainder = targetSum - numbers[i];
            ArrayList<Integer> remainderCombo = bestSumMemo(remainder, numbers, memo);
            if (remainderCombo != null) {
                ArrayList<Integer> combo = new ArrayList<Integer>(); // have to make a new object instead of just using remainderCombo because shortestCombo is reused over the course of the loop
                combo.addAll(remainderCombo);
                combo.add(numbers[i]);
                // If shortestCombo is null or if combo is shorter than the shortest combo, save
                // remainder combo as new shortest.
                shortestCombo = (shortestCombo == null || combo.size() < shortestCombo.size()) ? combo : shortestCombo;
            }
        }

        // store shortestCombo in memo so it can be recalled instead of repeat
        // calculation
        memo[targetSum] = shortestCombo;
        return shortestCombo;
    }
    
    /**
     * Usses Tabulation. <br></br>
     * Let m = targetSum, n = numbers.length <br></br>
     * Time: O(n*m^2) (same as howSum but with if statement O(1) to see if combo is shorter) <br></br>
     * Space: O(m^2) (same as howSum)
     * @param targetSum
     * @param numbers
     * @return
     */
    public static int[] bestSumTab(int targetSum, int[] numbers) {
        int[][] table = new int[targetSum + 1][];
        table[0] = new int[0];

        for (int i = 0; i < table.length; i++) { // for each number in the table
            if (table[i] != null) {
                for (int j = 0; j < numbers.length; j++) { // want to iterate for each number in combination
                    if (i + numbers[j] <= targetSum) { // want to check next number if current sums out of bounds of targetSum
                        int[] combination = new int[table[i].length + 1]; // length of prev slot, plus another slot for new number
                        for (int k = 0; k < combination.length - 1; k++)
                            combination[k] = table[i][k];
                        combination[combination.length - 1] = numbers[j]; // add the number to complete the sum
                        if (table[i + numbers[j]] == null || combination.length < table[i + numbers[j]].length)
                            table[i + numbers[j]] = combination; // only take the sum combination if it is new or shorter
                    }
                }
            }
        }

        return table[targetSum];
    }
}
