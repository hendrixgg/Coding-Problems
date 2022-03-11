import java.util.Scanner;

public class Problem_489C_Given_Length_and_Sum_of_Digits {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int numDigits = sc.nextInt(), sumDigits = sc.nextInt();
        sc.close();

        System.out.println(min_n_max_Num(numDigits, sumDigits));
    }

    /**
     * Finds the minimum and maximum possible non-negative numbers given 1 <=
     * {@code numDigits} <= 100 and 0 <= {@code sumDigits} <= 900. returns -1 -1 if
     * a decimal number cannot fit the criteria. Without leading zeros.<br>
     * </br>
     * 
     * Let m = numDigits, s = sumDigits, n_k = current digit with n_0 being the
     * first digit.<br>
     * </br>
     * To get the smallest number, you want to put the smallest possible digits it
     * the highest place value. And for the largest number, you want the smallest
     * digits at the lowest place value. The smallest digit being 0 and the largest
     * being 9.<br>
     * </br>
     * The digits can be found by this relation: <br>
     * </br>
     * n_k = = min(9,max(0, s - 9*(m - k - 1))) <br>
     * </br>
     * 
     * *****Although, for the smallest number, there can be no leading zeros. 
     * Therefore for the first digit on the min number can be at least 1.
     * 
     * 
     * @param numDigits
     * @param sumDigits
     * @return
     */
    public static String min_n_max_Num(int numDigits, int sumDigits1) {
        if (sumDigits1 == 0 && numDigits > 1) // can't have leading zeros
            return "-1 -1";
        if ((double)sumDigits1 / (double)numDigits > 9) // digits would have to all be > 9. double values becaue 19/2 = 9.5
            return "-1 -1";

        String minNum = "";
        String maxNum = "";
        int n1 = 0, n2 = 0, sumDigits2 = sumDigits1;

        for (int i = 0; i < numDigits; i++) { // goes from smallest to largest digits
            n2 = Math.max(0,  sumDigits2 - 9*(numDigits - i - 1));
            if (i == 0 && numDigits > 1) // cannot start with a 0
                n1 = Math.max(1, sumDigits1 - 9*(numDigits - i - 1));
            else
                n1 = Math.max(0, sumDigits1 - 9*(numDigits - i - 1));
            minNum = minNum + n1; // want the smaller digits first for lower number
            maxNum = n2 + maxNum; // smaller digits last for higher number
            sumDigits1 -= n1;
            sumDigits2 -= n2;
        }

        return minNum + " " + maxNum;
    }
}
