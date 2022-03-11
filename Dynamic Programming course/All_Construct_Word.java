import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class All_Construct_Word {
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
        // System.out.println(allConstructMemo(target, wordbank));

        // test cases
        if (n == 0) {
            String[] words1 = { "purp", "p", "ur", "le", "purpl" };
            System.out.println(allConstructMemo("purple", words1));
            // { { "purp", "le"}, { "p", "ur", "p", "le"} }
            String[] words2 = { "ab", "abc", "cd", "def", "abcd", "ef", "c" };
            System.out.println(allConstructMemo("abcdef", words2));
            // { { "ab", "c", "def" }, { "ab", "cd", "ef" }, { "abc", "def" }, { "abcd", "ef"} }
            String[] words3 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(allConstructMemo("skateboard", words3));
            // {}
            String[] words4 = {"a", "aa", "aaa", "aaaa", "aaaaa"};
            System.out.println(allConstructMemo("aaaaaaaaaaaaaaaaaaaaaaaaaaz", words4));
            // {}
        } else {
            String[] words1 = { "purp", "p", "ur", "le", "purpl" };
            System.out.println(allConstructTab("purple", words1));
            // { { "purp", "le"}, { "p", "ur", "p", "le"} }
            String[] words2 = { "ab", "abc", "cd", "def", "abcd", "ef", "c" };
            System.out.println(allConstructTab("abcdef", words2));
            // { { "ab", "c", "def" }, { "ab", "cd", "ef" }, { "abc", "def" }, { "abcd", "ef"} }
            String[] words3 = { "bo", "rd", "ate", "t", "ska", "sk", "boar"};
            System.out.println(allConstructTab("skateboard", words3));
            // {}
            String[] words4 = {"a", "aa", "aaa", "aaaa", "aaaaa"};
            System.out.println(allConstructTab("aaaaaaaaaaaaaaaaaaaaaaaaaaz", words4));
        }
    }

    public static ArrayList<ArrayList<String>> allConstructMemo(String target, String[] wordbank) {
        HashMap<String, ArrayList<ArrayList<String>>> memo = new HashMap<String, ArrayList<ArrayList<String>>>();
        return allConstructMemo(target, wordbank, memo);
    }


    /**
     * Let m = target.length() (height of tree) <br>
     * </br> Let n = wordbank.length (number of branches per level) <br>
     * </br> Time: O(n^m) <br>
     * </br> Space: O(m) --But it's really O(n^m) since all ways are stored. Really
     * only O(m) when ways are printed as you go.
     * 
     * @param target
     * @param wordbank
     * @param memo
     * @return
     */
    public static ArrayList<ArrayList<String>> allConstructMemo(String target, String[] wordbank, HashMap<String, ArrayList<ArrayList<String>>> memo) {
        
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>(); // stores all the arrays of string construction lists
        if (memo.containsKey(target)) {
            result.addAll(memo.get(target));
            return result;
        }
        if (target.equals("")) {
            result.add(new ArrayList<String>());
            return result;
        }

        for (int i = 0; i < wordbank.length; i++) {
            if (target.indexOf(wordbank[i]) == 0) {
                String suffix = target.substring(wordbank[i].length()); // remove the prefix of wordbank[i] and store the suffix
                Iterator<ArrayList<String>> suffixWays =  allConstructMemo(suffix, wordbank, memo).listIterator(); // call recursively on suffix to find all ways to make the suffix
                ArrayList<ArrayList<String>> targetWays = new ArrayList<ArrayList<String>>();
                while (suffixWays.hasNext()) { // for each way to make the suffix
                    Iterator<String> wayItr = suffixWays.next().listIterator();
                    ArrayList<String> ways = new ArrayList<String>();
                    ways.add(wordbank[i]); // add back the prefix
                    while (wayItr.hasNext()) // for each string in the wayIterator
                        ways.add(wayItr.next()); // add the next string that makes the suffix
                    targetWays.add(ways); // add that way to the array of ways to make the target
                }

                for (int j = 0; j < targetWays.size(); j++) // add all the different ways to the result array
                    result.add(targetWays.get(j));
            }
        }

        memo.put(target, result);
        return result;
    }

    public static ArrayList<ArrayList<String>> allConstructTab(String target, String[] wordbank) {
        ArrayList<ArrayList<ArrayList<String>>> table = new ArrayList<ArrayList<ArrayList<String>>>(target.length() + 1);
        for (int i = 0; i <= target.length(); i++)
            table.add(new ArrayList<ArrayList<String>>());
        table.get(0).add(new ArrayList<String>());

        for (int i = 0; i < target.length(); i++) {                             // iterate for each letter in the target word
            if(table.get(i) != null){                                           // if there is at least one combo in that slot
                for (String word : wordbank) {                                  // iterate for each word in the wordbank
                    if(target.substring(i).indexOf(word) == 0) {                // if target from index i has word as a prefix
                        for (ArrayList<String> arrayList : table.get(i)) {         // then for each combo of words already there
                            ArrayList<String> newcombination = new ArrayList<String>();
                            newcombination.addAll(arrayList);                          
                            newcombination.add(word);                           // add the new word
                            table.get(i + word.length()).add(newcombination);   // then put the new combo into the index corresponding to the last letter
                        }
                    }
                }   
            }
        }

        return table.get(target.length());
    }
}
