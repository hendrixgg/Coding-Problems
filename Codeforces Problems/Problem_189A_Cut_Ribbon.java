import java.util.Arrays;
import java.util.Scanner;

public class Problem_189A_Cut_Ribbon {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt(), maxPieces = 0; // total length of ribbon, maximum number of peices
        int[] sizes = new int[3]; // acceptable ribbon sizes
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < sizes.length; i++) {
            sizes[i] = sc.nextInt();
        }
        sc.close();

        if (sizes[0] == sizes[1] && sizes[0] == sizes[2] && sizes[1] == sizes[2]) { // if all sizes are equal
            // since it is guaranteed that at least one ribbon cutting works, the length
            // must be divisible by size[0]
            maxPieces = length / sizes[0];
        } else {
            Arrays.sort(sizes);
            if (sizes[0] == sizes[1]) {
                a = sizes[0];
                b = sizes[2]; // a < b
                int i = 0; // i is the number of large pieces required
                while (i != -1) {
                    if ((length - i * b) % a == 0) { // if i is the correct number of large pieces
                        maxPieces = i + (length - i * b) / a;
                        i = -2;
                    }
                    i++;
                }
            } else if (sizes[1] == sizes[2]) {
                a = sizes[0];
                b = sizes[1]; // a < b
                int i = 0; // i is the number of large pieces required
                while (i != -1) {
                    if ((length - i * b) % a == 0) { // if i is the correct number of large pieces
                        maxPieces = i + (length - i * b) / a;
                        i = -2;
                    }
                    i++;
                }
            } else { // a, b, and c are different
                a = sizes[0];
                b = sizes[1];
                c = sizes[2]; // a < b < c

                if (length % a != 0)
                    maxPieces = cutting(a, b, c, length);
                else
                    maxPieces = length / a;
                
            }
        }

        System.out.println(maxPieces);
    }

    public static int cutting(int a, int b, int c, int length) {
        int with_a = 0, with_b = 0, with_c = 0;
        // combos of b and c that a divides
        for (int j = 0; (length - j * b) > 0; j++) {
            for (int k = 0; (length - j * b - k * c) > 0; k++) {
                if ((length - j * b - k * c) % a == 0)
                    with_a = Math.max(j + k + (length - j * b - k * c) / a, with_a);
            }
        }
        // combos of a and c that b divides
        for (int i = 0; (length - i * a) > 0; i++) {
            for (int k = 0; (length - i * a - k * c) > 0; k++) {
                if ((length - i * a - k * c) % b == 0)
                    with_b = Math.max(i + k +(length - i * a - k * c) / b, with_b);
            }
        }
        // combos of a and b that c divides
        for (int i = 0; (length - i * a) > 0; i++) {
            for (int j = 0; (length - i * a - j * b) > 0; j++) {
                if ((length - i * a - j * b) % c == 0)
                    with_c = Math.max(i + j +(length - i * a - j * b) / c, with_c);
            }
        }
        

        return Math.max(Math.max(with_a, with_b), with_c);
    }


}