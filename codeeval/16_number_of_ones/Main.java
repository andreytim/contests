import java.io.BufferedReader;
import java.io.FileReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            int n = Integer.parseInt(line.trim());
            int counts = 0;
            while (n != 0) {
                if ((n & 1) == 1) counts++;
                //System.out.print(n + "=" + Integer.toBinaryString(n) + "; "); 
                n >>>= 1;
            }
            System.out.println(counts);
        }
    }

}
