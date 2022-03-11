import java.util.Scanner;

public class Problem_282A_Bit {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String userin = "";
        int x = 0;

        for(int i = 0; i < n; i++) {
            userin = input.next();
            switch(userin) {
                case "++X": x++; break;
                case "X++": x++; break;
                case "--X": x--; break;
                case "X--": x--; break;
                   default : ;
                }
            }
            System.out.println(x);

            input.close();
        }

}
