import java.util.Arrays;
import java.util.Scanner;

public class Problem_339A_Helpful_Maths {
    
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String str = input.next();
        int length = str.length();
        int[] nums = new int[(length/2) + 1];

        for (int i = 0; i < str.length(); i+=2) {
            nums[i/2] += Integer.parseInt(str.substring(i, i+1));
        }
        Arrays.sort(nums);

        str = "";

        for (int i = 0; i < length; i+=2) {
            str += nums[i/2];
            if(i < length-1)
            str += "+";
        }
        System.out.println(str);

        input.close();

    }

}
