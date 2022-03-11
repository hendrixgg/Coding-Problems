import java.util.Arrays;
import java.util.Scanner;

public class Problem_706B_Interesting_Drink {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int[] shopPrices = new int[input.nextInt()];
        for (int i = 0; i < shopPrices.length; i++) {
            shopPrices[i] = input.nextInt();
        }
        Arrays.sort(shopPrices);

        int[] daysToBuy = new int[input.nextInt()];
        for (int i = 0; i < daysToBuy.length; i++) {
            daysToBuy[i] = searchHighest(shopPrices, input.nextInt());
        }
        input.close();

        for (int i = 0; i < daysToBuy.length; i++) {
            System.out.println(daysToBuy[i]);
        }

    }

    private static int searchHighest(int[] list, int item) {
        int l = -1;              // the highest priced shop I CAN BUY from
        int r = list.length;     // the lowest priced shop I CAN'T BUY from
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (list[m] <= item)
                l = m;
            else
                r = m;
        }
        return l + 1;
    }
}