import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class Main {
    
    private static int isSelfDescribing(String n) {
        int[] digitCounts = new int[10];
        char[] chArr = n.toCharArray();
        for (char ch : chArr) {
            digitCounts[ch - '0'] += 1;
        }        
        for (int i = 0; i < chArr.length; i++) {
            if (chArr[i] - '0' != digitCounts[i]) return 0;
        }
        return 1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(isSelfDescribing(line));
        }
    }

}
