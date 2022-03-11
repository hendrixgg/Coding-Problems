import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class How_Sum {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        // -------USER INPUT------- //
        // int targetSum = sc.nextint();
        // int max = sc.nextInt();
        // int[] numbers = new int[max];
        // for (int i = 0; i < numbers.length; i++)
        // numbers[i] = sc.nextInt();
        // -------USER INPUT------- //
        int n = sc.nextInt(); // 0 for memoization, anything else for tabulation
        sc.close();

        // test cases
        if (n == 0) {
            int[] nums1 = { 2, 3 };
            System.out.println(howSumMemo(7, nums1)); // [3, 2, 2]
            int[] nums2 = { 5, 3, 4, 7 };
            System.out.println(howSumMemo(7, nums2)); // [4, 3]
            int[] nums3 = { 2, 4 };
            System.out.println(howSumMemo(7, nums3)); // null
            int[] nums4 = { 2, 3, 5 };
            System.out.println(howSumMemo(8, nums4)); // [2, 2, 2, 2]
            int[] nums5 = { 7, 14 };
            System.out.println(howSumMemo(300, nums5)); // null
        } else {
            int[] nums1 = { 2, 3 };
            System.out.println(Arrays.toString(howSumTab(7, nums1))); // [3, 2, 2]
            int[] nums2 = { 5, 3, 4, 7 };
            System.out.println(Arrays.toString(howSumTab(7, nums2))); // [7]
            int[] nums3 = { 2, 4 };
            System.out.println(Arrays.toString(howSumTab(7, nums3))); // null
            int[] nums4 = { 2, 3, 5 };
            System.out.println(Arrays.toString(howSumTab(8, nums4))); // [2, 2, 2, 2]
            int[] nums5 = { 7, 14 };
            System.out.println(Arrays.toString(howSumTab(300, nums5))); // null
        }

    }

    public static ArrayList<Integer> howSumMemo(int targetSum, int[] numbers) {
        ArrayList<Integer>[] memo = new ArrayList[(int) (targetSum + 1)];
        for (int i = 1; i < memo.length; i++) {
            memo[i] = new ArrayList<Integer>();
        }
        return howSumMemo(targetSum, numbers, memo);
    }

    /**
     * Time complexity : let m = targetSum, n = numbers.length <br>
     * </br>
     * n is number of branches, m is height of tree <br>
     * </br>
     * Brute force: <br>
     * </br>
     * Since this is a tree data structure time = O(n^m * m) = O(n^m) <br>
     * </br>
     * n^m because each level has n^level nodes and nodes are multiplied by branches
     * for each level in worst case. <br>
     * </br>
     * *m because the array.add(int e) is O(1) and it happens at most m times <br>
     * </br>
     * space: O(m) <br>
     * </br>
     * Memoized version: <br>
     * </br>
     * Since it is now a tree with 4 branches at most for each level, time =
     * O(n*m*m) = O(n*m^2) <br>
     * </br>
     * *m extra because the array.add(int e) is O(1) and it happens at most m times
     * <br>
     * </br>
     * space: O(m*m) = O(m^2) because of the memo has m arrays that can each be up
     * to length m.
     * 
     * @param targetSum
     * @param numbers
     * @param array
     * @return an Arraylist that contains a set of numbers which add to the
     *         targetSum
     */
    public static ArrayList<Integer> howSumMemo(int targetSum, int[] numbers, ArrayList<Integer>[] memo) {
        /**
         * Base cases:
         * 1. targetSum == 0 --> return empty array
         * 2. targetSum < 0 --> return null
         * 3. memo[targetSum] == null --> return null
         * 4. memo[targetSum] != -1L --> return ArrayList @ memo[targetSum]
         */
        if (targetSum == 0)
            return new ArrayList<Integer>();
        if (targetSum < 0)
            return null;
        if (memo[targetSum] == null) // if done and not worked
            return null;
        if (memo[targetSum].size() != 0) // if already done and worked // memo[0] is an empty array
            return memo[targetSum];

        for (int i = 0; i < numbers.length; i++) {
            int remainder = targetSum - numbers[i];
            ArrayList<Integer> remainderList = howSumMemo(remainder, numbers, memo);
            if (remainderList != null) {
                remainderList.add(numbers[i]);
                memo[targetSum] = remainderList;
                return memo[targetSum];
            }
        }
        memo[(int) targetSum] = null; // did not work
        return null;
        
    }

    /**
     * Uses tabulation. <br></br>
     * Time complexity : let m = targetSum, n = numbers.length <br>
     * </br>
     * Time: O(m*n*m) = O(m^2*n) <br></br>
     * Space: O(m^2)
     * @param targetSum
     * @param numbers
     * @return
     */
    public static int[] howSumTab(int targetSum, int[] numbers) {
        int[][] table = new int[targetSum + 1][];
        table[0] = new int[0]; // 0th slot is an empty array

        for (int i = 0; i <= targetSum; i++) {
            if (table[i] != null) {
                for (int j = 0; j < numbers.length && i + numbers[j] <= targetSum; j++) { // repeat for each element in the number array, as long as it it <= targetSum
                    int[] combination = new int[table[i].length + 1]; // the numbers that sum to i 
                    for (int k = 0; k < table[i].length; k++) // for each number in sum already in table
                        combination[k] = table[i][k];
                    combination[combination.length - 1] = numbers[j]; // add new number to the sum
                    table[i + numbers[j]] = combination; // store sum in the table
                }
            }
        }

        return table[targetSum];
    }
}
