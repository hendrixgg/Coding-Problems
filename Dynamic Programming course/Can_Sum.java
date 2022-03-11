import java.util.Scanner;

public class Can_Sum {
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
        if (n != 0) {
            long[] nums1 = { 2, 3 };
            System.out.println(canSumTab(7, nums1)); // true
            long[] nums2 = { 5, 3, 4, 7 };
            System.out.println(canSumTab(7, nums2)); // true
            long[] nums3 = { 2, 4 };
            System.out.println(canSumTab(7, nums3)); // false
            long[] nums4 = { 2, 3, 5 };
            System.out.println(canSumTab(8, nums4)); // true
            long[] nums5 = { 7, 14 };
            System.out.println(canSumTab(300, nums5)); // false
        } else {
            long[] nums1 = { 2, 3 };
            System.out.println(canSumMemo(7, nums1)); // true
            long[] nums2 = { 5, 3, 4, 7 };
            System.out.println(canSumMemo(7, nums2)); // true
            long[] nums3 = { 2, 4 };
            System.out.println(canSumMemo(7, nums3)); // false
            long[] nums4 = { 2, 3, 5 };
            System.out.println(canSumMemo(8, nums4)); // true
            long[] nums5 = { 7, 14 };
            System.out.println(canSumMemo(300, nums5)); // false
        }

    }

    public static boolean canSumMemo(long targetSum, long[] numbers) {
        return canSumMemo(targetSum, numbers, new int[(int)targetSum + 1]); 
    }
    
    /**
     * Uses Memoization. <br>
     * </br>
     * Time: O(m*n) Space: O(m) <br>
     * </br>
     * Since this is a tree of length m with n branches at most per level.
     * 
     * @param targetSum
     * @param numbers
     * @param memo
     * @return true/false
     */
    public static boolean canSumMemo(long targetSum, long[] numbers, int[] memo) {
        /**
         * Base cases: 
         * 1. targetSum == 0 --> true
         * 2. targetSum < 0 --> false
         * 3. memo[targetSum] == 1 --> false
         * 4. memo[targetSum] == 2 --> true
         */
        if (targetSum == 0)
            return true;
        if (targetSum < 0)
            return false;
        if (memo[(int) targetSum] == 1)
            return false;
        if (memo[(int) targetSum] == 2)
            return true;

        /**
         * Now iterate for each number in the array a recursive call of canSum with
         * (targetSum = targetSum - numbers[i]).
         */
        for (int i = 0; i < numbers.length; i++) {
            long remainder = targetSum - numbers[i];
            if (canSumMemo(remainder, numbers, memo)){
                memo[(int) targetSum] = 2; // store as true
                return true; // if a possibillity worked
            }
        }

        memo[(int) targetSum] = 1; // store as false
        return false; // if none of the possibilities worked
    }

    /**
     * Uses Tabulation. <br>
     * </br>
     * Time: O(m*n) Space: O(m) <br>
     * /br> since it iterates m times, each iteration iterates n times and all is
     * stored in an array of lenth m.
     * 
     * @param targetSum
     * @param numbers
     * @return true/false
     */
    public static boolean canSumTab(long targetSum, long[] numbers) {
        boolean[] table = new boolean[(int) targetSum + 1];
        table[0] = true; // can always achieve a sum of 0 by taking no elements
        for (int i = 0; i < targetSum; i++) {
            if (table[i]) { // if on a possible sum given the possible numbers
                for (int j = 0; j < numbers.length && i + numbers[j] <= targetSum; j++) // for each number in the number array
                    table[i + (int)numbers[j]] = true;
            }
        }
        return table[(int) targetSum];
    }

}
