import java.util.Scanner;

public class Problem_131A_cAPS_Lock {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        String s = input.next();
        input.close();
        boolean allUpper = true;
        boolean allButFirstUpper = true;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 97 ) {
                allUpper = false;
                allButFirstUpper = (i == 0) ? true : false;
            }
        }

        if (allUpper)
            s = s.toLowerCase();
        else if (allButFirstUpper)
            s = s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase();


            

        System.out.println(s);
    }
}
