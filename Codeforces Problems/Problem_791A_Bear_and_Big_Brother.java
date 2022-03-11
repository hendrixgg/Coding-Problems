import java.util.Scanner;

public class Problem_791A_Bear_and_Big_Brother {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int year = 0;

        while(a <= b) {
            a *= 3;
            b *= 2;
            year++;
        }

        System.out.println(year);
            input.close();

    }

}