import java.io.BufferedReader;
import java.io.FileReader;

public class Main { 
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while((line = reader.readLine()) != null) {
            int res = 0;
            int pow = 1;
            for (int i = line.length() - 1; i >= 0; i--) {
                char ch = line.charAt(i);
                int num = ch - '0';
                if (ch >= 'a') {
                    num = ch - 'a' + 10;
                }
                res += pow * num;
                pow *= 16;
            }
            System.out.println(res);
        }
    }

}
