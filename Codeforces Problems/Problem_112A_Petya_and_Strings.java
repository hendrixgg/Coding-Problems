import java.util.Scanner;

public class Problem_112A_Petya_and_Strings {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String s1 = input.next(), s2 = input.next();

        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();

        int result = s1.compareTo(s2);

        if(result > 0) //s1 greater than s2
        System.out.println(1);
        else if(result == 0) //s1 equal to s2
        System.out.println(0);
        else if(result < 0) //s1 less than s2
        System.out.println(-1);

        input.close();
    }

}
