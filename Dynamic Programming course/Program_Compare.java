import java.util.Scanner;

public class Program_Compare {
    static Scanner input = new Scanner(System.in);

    public static void main(String args[]) {
        int n;
        do {
            System.out.println("(1) To test grid traveler with start from end iterative method.");
            System.out.println(
                    "(2) To test grid traveler with start from beginning recursive method.");
            System.out.println("(3) To test grid traveler with mathematical combinatorics method.");
            System.out.println("(4) Test CanSumTab1");
            System.out.println("(5) Test CanSumTab2");
            System.out.println("(0) to quit");
            System.out.print("Your choice: ");
            n = promptForNumber(input);
            System.out.println();
            switch (n) {
            case 1:
                gridTraveler1();
                break;
            case 2:
                gridTraveler2();
                break;
            case 3:
                gridTravelerCombo();
                break;
            case 4:
                canSumTab1();
                break;
            case 5:
                canSumTab2();
                break;
            }
            System.out.println();
        } while (n != 0);
    }

    /**
     * promptForNumber - int
     * 
     * @param in a Scanner to read integer values from
     * @return an integer value read from the Scanner
     */
    public static int promptForNumber(Scanner in) {
        int value = 0;
        boolean done = false;
        while (!done) {
            if (in.hasNextInt()) {
                value = in.nextInt();
                in.nextLine(); // Move to the next line
                done = true;
            } else {
                System.out.println("ERROR!  Input not an integer!");
                in.nextLine(); // clear input that is not an integer
                System.out.print("Enter an integer: ");
            }
        }
        return value;
    }

    public static void gridTraveler1() {
        int k1 = 34, k2 = 34, runs = 100000;
        System.out.println();
        long startTime, endTime, durationInMillis;
        long sum = 0, ans = 0;
        startTime = System.currentTimeMillis();
        for (int i = 0; i < runs; i++) {

            ans = Grid_Traveler_Problem.gridTraveler1(k1, k2);
            endTime = System.currentTimeMillis();

            durationInMillis = (endTime - startTime); // Total execution time in milli seconds
            sum = sum + durationInMillis;
            startTime = System.currentTimeMillis();
        }
        System.out.printf("%,d runs of finding the number of paths in a %dx%d grid took %d milliseconds, ans: %d%n", runs, k1, k2, sum, ans);
    }

    public static void gridTraveler2() {
        int k1 = 34, k2 = 34, runs = 100000;
        System.out.println();
        long startTime, endTime, durationInMillis;
        long sum = 0, ans = 0;
        startTime = System.currentTimeMillis();
        for (int i = 0; i < runs; i++) {

            ans = Grid_Traveler_Problem.gridTraveler1(k1, k2);
            endTime = System.currentTimeMillis();

            durationInMillis = (endTime - startTime); // Total execution time in milli seconds
            sum = sum + durationInMillis;
            startTime = System.currentTimeMillis();
        }
        System.out.printf("%,d runs of finding the number of paths in a %dx%d grid took %d milliseconds, ans: %d%n", runs, k1, k2, sum, ans);
    }

    public static void gridTravelerCombo() {
        int k1 = 34, k2 = 34, runs = 100000;
        System.out.println();
        long startTime, endTime, durationInMillis;
        long sum = 0, ans = 0;
        startTime = System.currentTimeMillis();
        for (int i = 0; i < runs; i++) {

            ans = Grid_Traveler_Problem.gridTravelerCombo(k1, k2);
            endTime = System.currentTimeMillis();

            durationInMillis = (endTime - startTime); // Total execution time in milli seconds
            sum = sum + durationInMillis;
            startTime = System.currentTimeMillis();
        }
        System.out.printf("%,d runs of finding the number of paths in a %dx%d grid took %d milliseconds, ans: %d%n", runs, k1, k2, sum, ans);
    }

    
    public static void canSumTab1() {
        int runs = 1000000, num = 300;
        long[] nums = { 7, 14 };
        boolean ans = false;
        System.out.println();
        long startTime, endTime, durationInMillis;
        long sum = 0;
        startTime = System.currentTimeMillis();
        for (int i = 0; i < runs; i++) {

            ans = Can_Sum.canSumTab(num, nums);
            endTime = System.currentTimeMillis();

            durationInMillis = (endTime - startTime); // Total execution time in milli seconds
            sum = sum + durationInMillis;
            startTime = System.currentTimeMillis();
        }
        System.out.printf("%,d runs of finding the number of word combos in a took %d milliseconds, ans: %b", runs, sum, ans);
    }

    public static void canSumTab2() {
        int runs = 1000000, num = 300;
        long[] nums = { 7, 14 };
        boolean ans = false;
        System.out.println();
        long startTime, endTime, durationInMillis;
        long sum = 0;
        startTime = System.currentTimeMillis();
        for (int i = 0; i < runs; i++) {

            ans = Can_Sum.canSumTab(num, nums);
            endTime = System.currentTimeMillis();

            durationInMillis = (endTime - startTime); // Total execution time in milli seconds
            sum = sum + durationInMillis;
            startTime = System.currentTimeMillis();
        }
        System.out.printf("%,d runs of finding the number of word combos in a took %d milliseconds, ans: %b", runs, sum, ans);
    }

}
