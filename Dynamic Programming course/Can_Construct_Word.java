import java.util.HashMap;
import java.util.Scanner;

public class Can_Construct_Word {
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
            String[] words1 = { "ab", "abc", "cd", "def", "abcd" };
            System.out.println(canConstructMemo("abcdef", words1));                                  //   true
            String[] words2 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(canConstructMemo("skateboard", words2));                              //   false
            String[] words3 = { "a", "p", "ent", "enter", "ot", "o", "t" };
            System.out.println(canConstructMemo("enterapotentpot", words3));                         //   true
            String[] words4 = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
            System.out.println(canConstructMemo("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", words4));//   false
        } else {
            String[] words1 = { "ab", "abc", "cd", "def", "abcd" };
            System.out.println(canConstructTab("abcdef", words1));                                  //   true
            String[] words2 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(canConstructTab("skateboard", words2));                              //   false
            String[] words3 = { "a", "p", "ent", "enter", "ot", "o", "t" };
            System.out.println(canConstructTab("enterapotentpot", words3));                         //   true
            String[] words4 = { "e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
            System.out.println(canConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", words4));//   false
        }


    }

    public static boolean canConstructMemo(String target, String[] wordbank) {
        HashMap<String, Boolean> memo = new HashMap<String, Boolean>();
        return canConstructMemo(target, wordbank, memo);
    }

    /**
     * Let: m = target.length(), n = wordbank.length <br>
     * </br>
     * Brute Force: <br>
     * </br>
     * Time: O(n^m * m) since branches^height * each_substring <br>
     * </br>
     * Space: O(m^2) since call_stack_height * each_substring <br>
     * </br>
     * Memoized: <br>
     * </br>
     * Time: O(n * m^2) since n branches * levels * substrings <br>
     * </br>
     * Space: O(m^2) same as Brute Force
     * 
     * @param target
     * @param wordbank
     * @return
     */
    public static boolean canConstructMemo(String target, String[] wordbank, HashMap<String, Boolean> memo) {
        // base cases
        if (memo.containsKey(target))
            return memo.get(target);
        if (target.equals(""))
            return true;
        
        for (String word : wordbank) { // for each word in wordbank
            if (target.indexOf(word) == 0) { // substring will be found at index 0 if it is a prefix
                String suffix = target.substring(word.length()); // suffix is the target minus word
                if (canConstructMemo(suffix, wordbank, memo)) {
                    memo.put(target, true);
                    return true;
                }
            }
        }
        memo.put(target, false);
        return false;
    }

    /**
     * Let m = target.length(), n = wordbank.length <br>
     * </br>
     * Time: O(m*n*m) = O(m^2*n) <br>
     * </br>
     * Space: O(m)
     * 
     * @param target
     * @param wordbank
     * @return
     */
    public static boolean canConstructTab(String target, String[] wordbank) {
        boolean[] table = new boolean[target.length() + 1];
        table[0] = true;
        
        for (int i = 0; i < table.length; i++) {
            if (table[i]) { // if true
                for (String word : wordbank) { // check each word in wordbank
                    // if word mathces characters starting at pos i (is a prefix)
                    if (i + word.length() <= target.length() && target.substring(i, i + word.length()).equals(word))
                        table[i + word.length()] = true; // word also has to not be longer than target
                }
            }
        }
        return table[target.length()];
    }
}
