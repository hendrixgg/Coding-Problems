import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem_58A_Chart_Room {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        String s = input.next();
        input.close();

        Pattern pattern = Pattern.compile("[^helo]*h+[a-z]*e+[a-z]*l+[a-z]*l*[a-z]o+", Pattern.CASE_INSENSITIVE);
        Matcher string = pattern.matcher(s);
        boolean matchFound = string.find();

        if (matchFound)
            System.out.println("YES");
        else
            System.out.println("NO");        
    
    }
}
