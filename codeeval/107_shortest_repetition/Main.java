import java.io.BufferedReader;
import java.io.FileReader;

public class Main {
    
    public static int getRepetitionLength(String line) {
        for (int i = 1; i < line.length()/2 + 1; i++) {
            String s = line;
            while (s.length() >= i) {
                if (!s.substring(0, i).equals(line.substring(0, i))) {
                    break;
                }
                s = s.substring(i);
            }
            if (s.isEmpty()) {
                return i;
            }
        }    
        return line.length();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(getRepetitionLength(line));
        }
    }

}
