import java.util.Scanner;

public class Problem_71A_Way_Too_long_Words {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        String[] words = new String[n];
        String replace;

        for(int i = 0; i < n; i++){
            words[i] = input.next();
            if(words[i].length() > 10){
                replace = "";
                replace += words[i].substring(0,1) + (words[i].length() - 2) 
                + words[i].substring(words[i].length()-1, words[i].length());
                words[i] = replace;
            }
        }

        for(int i = 0; i < words.length; i++){
            System.out.println(words[i]);
        }

        input.close();
    }

}