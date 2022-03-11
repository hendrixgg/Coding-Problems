import java.util.Scanner;

public class Problem_266A_Stones_on_the_Table {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String stones = input.next();
        int remove = 0;

        for(int i = 0; i < n; i++) {
            if(i < n-1 && stones.charAt(i) == stones.charAt(i+1))
            remove++;
        }
 
        System.out.println(remove);

        input.close();

    }

}
