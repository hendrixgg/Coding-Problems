import java.util.Scanner;

public class Problem_266B_Queue_at_the_School {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt(), t = input.nextInt();
        String s = input.next();
        input.close();
        char [] queue = new char[n];
        for (int i = 0; i < n; i++) {
            queue[i] = s.charAt(i);
        }
        boolean[] swapWithPrev = new boolean[n-1];

        // repeats for each second
        for (int i = 0; i < t; i++) {
            // repeats for each child
            for (int j = 0; j < n-1; j++) {
                if (queue[j] == 'B' && queue[j + 1] == 'G')
                    swapWithPrev[j] = true;
            }
            // repeats for each child
            for (int j = 0; j < swapWithPrev.length; j++) {
                // if swap is supposed to happen, swap
                if (swapWithPrev[j]) {
                    queue[j] = 'G';
                    queue[j + 1] = 'B';
                }
            }
            // clear all required swaps
            for (int j = 0; j < swapWithPrev.length; j++) {
                swapWithPrev[j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(queue[i]);
        }
    }
}