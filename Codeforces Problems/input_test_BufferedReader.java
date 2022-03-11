import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

/**
 * Speed on https://www.spoj.com/problems/INTEST/ is 0.65 seconds (For integers).
 */
class input_test_BufferedReader {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int count = 0;
        while (n-- > 0) {
            int num = Integer.parseInt(br.readLine());
            if (num % k == 0)
                count++;
        }
        System.out.println(count);
    }
}
