import java.util.Scanner;

public class Problem_158A_Next_Round {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int k = input.nextInt();
        int[] scores = new int[n];
        int advancers = 0;
        
        for (int i = 0; i < scores.length; i++) {
            scores[i] = input.nextInt();
        }
        for(int i = 0; i < scores.length; i++) {
            if(scores[i] >= scores[k-1] && scores[i] > 0)
                advancers++;
        }

        System.out.println(advancers);

        input.close();
    }

}
