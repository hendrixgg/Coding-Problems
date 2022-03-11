import java.util.Scanner;

/**
 * Speed on https://www.spoj.com/problems/INTEST/ is 3.40 seconds (For integers).
 */
class input_test_Scanner {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();// reading integer
        int k = sc.nextInt();
        int count = 0;
        while (n-- > 0) {
            int num = sc.nextInt();
            if (num % k == 0)
                count++;
        }
        System.out.println(count);
        sc.close();
    }
}
