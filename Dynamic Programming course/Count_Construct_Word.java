import java.util.HashMap;
import java.util.Scanner;

public class Count_Construct_Word {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        // -------USER INPUT------- //
        // String target = sc.next();          // 1st line contains the target word then
        // int num = sc.nextInt();             // the number of elements in wordbank
        // String[] wordbank = new String[num];// 2nd line
        // for (int i = 0; i < num; i++) {
        //     wordbank[i] = sc.next();        // each element in the wordbank array
        // }
        // -------USER INPUT------- //
        int n = sc.nextInt(); // 0 for memoization, anything else for tabulation
        sc.close();

        // test cases
        if (n == 0) {
            String[] words1 = { "purp", "p", "ur", "le", "purpl" };
            System.out.println(countConstructMemo("purple", words1));                                  //   2
            String[] words2 = { "ab", "abc", "cd", "def", "abcd" };
            System.out.println(countConstructMemo("abcdef", words2));                                  //   1
            String[] words3 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(countConstructMemo("skateboard", words3));                              //   0
            String[] words4 = { "a", "p", "ent", "enter", "ot", "o", "t" };
            System.out.println(countConstructMemo("enterapotentpot", words4));                         //   true
            String[] words5 = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee", "ef", "eef", "eeef", "eeeef", "eeeeef", "eeeeeef"};
            System.out.println(countConstructMemo("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", words5));//   0 (without the f's)
        } else {
            String[] words1 = { "purp", "p", "ur", "le", "purpl" };
            System.out.println(countConstructTab("purple", words1));                                  //   2
            String[] words2 = { "ab", "abc", "cd", "def", "abcd" };
            System.out.println(countConstructTab("abcdef", words2));                                  //   1
            String[] words3 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(countConstructTab("skateboard", words3));                              //   0
            String[] words4 = { "a", "p", "ent", "enter", "ot", "o", "t" };
            System.out.println(countConstructTab("enterapotentpot", words4));                         //   true
            String[] words5 = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee", "ef", "eef", "eeef", "eeeef", "eeeeef", "eeeeeef"};
            System.out.println(countConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", words5));//   0
        }
    }

    public static long countConstructMemo(String target, String[] wordbank) {
        HashMap<String, Long> memo = new HashMap<String, Long>();
        return countConstructMemo(target, wordbank, memo);
    }

    /**
     * Let: m = target.length(), n = wordbank.length <br>
     * </br>
     * BruteForce:
     * <ul>
     * <li>Time: O(n^m * m)</li>
     * <li>Space: O(m^2)</li>
     * </ul>
     * Memoized:
     * <ul>
     * <li>Time: O(n * m^2)</li>
     * <li>Space: O(m^2)</li>
     * </ul>
     * 
     * @param target
     * @param wordbank
     * @param memo
     * @return the number of different ways words from the wordbank array can be
     *         concatenated together to from the target string.
     */
    public static long countConstructMemo(String target, String[] wordbank, HashMap<String, Long> memo) {
        // base cases
        if (target.equals(""))
            return 1;
        if (memo.containsKey(target))
            return memo.get(target);

        long totalCount = 0L;

        for (String word : wordbank) { // for each word in wordbank
            if (target.indexOf(word) == 0) { // substring will be found at index 0 if it is a prefix
                String suffix = target.substring(word.length()); // suffix is the target minus word
                long numWaysForRest = countConstructMemo(suffix, wordbank, memo);
                totalCount += numWaysForRest;
            }
        }

        memo.put(target, totalCount); // did not work so return 0 ways
        return totalCount;
    }

    public static long countConstructTab(String target, String[] wordbank) {
        long[] table = new long[target.length() + 1];
        table[0] = 1;

        for (int i = 0; i < table.length; i++) { // for each letter in the target word
            for (String word : wordbank) {
                // if word mathces characters starting at pos i (is a prefix) // also, word.length cannot be too long
                if (i + word.length() <= target.length() && target.substring(i, i + word.length()).equals(word))
                    table[i + word.length()] += table[i]; // increment by number of ways from current pos
            }
        }

        return table[target.length()];
    }
}