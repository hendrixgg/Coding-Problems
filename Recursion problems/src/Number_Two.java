package src;
import java.util.Scanner;

/**
 * Write a function that takes two inputs n and m and outputs the number of
 * unique paths from the top left corner to the bottom right corner of the grid.
 * 
 * 
 * Constraints: you can only move down or right 1 unit at a time.
 *  
 * 
 * Step 1: What is the simplest possible input? 
 * 
 * grid_paths(1,m) and grid_paths(n,1) both equal 1. This is the base case. 
 * 
 * 
 * Step 2: Relate har cases to simpler cases. 
 * 
 * grid_paths(3,3) = grid_praths(3,2) + grid_paths(2,3) 
 * 
 *
 * Step 3: Generalize the pattern.
 * 
 * grid_paths(n, m) = grid_paths(n - 1, m) + grid_paths(n, m - 1)
 */
public class Number_Two {
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        sc.close();

        System.out.println(grid_paths(n, m)); // without memoization
        System.out.println();
        System.out.println();
        System.out.println(grid_pathsM(n, m)); // with memoizations
    
    }

    static int grid_paths(int n, int m) {
        if (n == 1 || m == 1) 
            return 1;
        else
            return grid_paths(n - 1, m) + grid_paths(n, m - 1);
    }

    static int grid_pathsM(int n, int m) {
        int[][] memo = new int[n + 1][m + 1];
        return grid_pathsM(n, m, memo);
    }

    static int grid_pathsM(int n, int m, int[][] memo) {
        if (n == 1 || m == 1) 
            return 1;
        else if (memo[n][m] != 0)
            return memo[n][m];
        else {
            memo[n - 1][m] = grid_paths(n - 1, m);
            memo[n][m - 1] = grid_paths(n, m - 1);
        }
            return memo[n - 1][m] + memo[n][m - 1];
    }
}
