import java.util.Scanner;

public class Problem_546A_Soldier_and_Bananas {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int costPer = input.nextInt();
        int money = input.nextInt();
        int bananasWanted = input.nextInt(); 
        int toBorrow = 0;
        for (int i = 1; i <= bananasWanted; i++) {
            toBorrow += (i)*costPer;
        }
        toBorrow -= money;
        if(toBorrow < 0)
        toBorrow = 0;
        
        System.out.println(toBorrow);

        input.close();

    }

}