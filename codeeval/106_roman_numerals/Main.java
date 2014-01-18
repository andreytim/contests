import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Map;
import java.util.HashMap;

public class Main {

    public static final int[] div = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    public static final Map<Integer, String> decToRoman = new HashMap<Integer, String>();
    static {
        decToRoman.put(1, "I");
        decToRoman.put(5, "V");
        decToRoman.put(10, "X");
        decToRoman.put(50, "L");
        decToRoman.put(100, "C");
        decToRoman.put(500, "D");
        decToRoman.put(1000, "M");
        decToRoman.put(4, "IV");
        decToRoman.put(9, "IX");
        decToRoman.put(40, "XL");
        decToRoman.put(90, "XC");
        decToRoman.put(400, "CD");
        decToRoman.put(900, "CM");
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            int n = Integer.parseInt(line), i = 0;
            StringBuilder res = new StringBuilder();
            while (n > 0) {
                int count = n / div[i];
                for (int j = 0; j < count; j++) res.append(decToRoman.get(div[i]));
                n %= div[i];
                i++;
            }
            System.out.println(res.toString());
        }
    }

}
