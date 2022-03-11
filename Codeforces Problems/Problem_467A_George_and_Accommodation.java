import java.util.Scanner;

/**
 * <h4>Input
 * <h4>
 * <p>
 * The first line contains a single integer n (1 ≤ n ≤ 100) — the number of
 * rooms.
 * </p>
 * <p>
 * The i-th of the next n lines contains two integers pi and qi (0 ≤ pi ≤ qi ≤
 * 100) — the number of people who already live in the i-th room and the room's
 * capacity.
 * </p>
 * <h4>Output</h4>
 * <p>
 * Print a single integer — the number of rooms where George and Alex can move
 * in.
 * </p>
 */
public class Problem_467A_George_and_Accommodation {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), current, capacity;
        int availableRooms = 0;
        //take input for each room
        for (int i = 0; i < n; i++) {
            current = input.nextInt();
            capacity = input.nextInt();
            if (capacity - current >= 2)
                availableRooms++;
        }
        System.out.println(availableRooms);
        input.close();
    
    }
}
