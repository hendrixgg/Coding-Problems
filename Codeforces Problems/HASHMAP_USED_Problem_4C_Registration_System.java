import java.util.HashMap;
import java.util.Scanner;

/**
 * <ul>
 * <li>The {@code username} entered is used as the <b>KEY</b> for the hashmap
 * entry.</li>
 * </ul>
 * <br>
 * <ul>
 * <li>The number of times the {@code username} was entered is the <b>VALUE</b>
 * associated with the entry.</li>
 * </ul>
 */
public class HASHMAP_USED_Problem_4C_Registration_System {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> userNames = new HashMap<String, Integer>();
        int num = sc.nextInt(), count;
        String name = "";
        for (int i = 0; i < num; i++) {
            name = sc.next();
            if (userNames.containsKey(name)) {
                count = userNames.get(name);
                System.out.println(name + count);
                userNames.put(name, count + 1);

            } else {
                userNames.put(name, 1);
                System.out.println("OK");
            }
        }
        sc.close();

    }
}