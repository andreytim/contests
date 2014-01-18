import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.FileReader;

public class Solve {

    public static void main(String ... args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] sets = line.split(";");
            String[] firstArr = sets[0].split(",");
            Set<String> secondArr = new HashSet<String>(Arrays.asList(sets[1].split(",")));
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < firstArr.length; i++) {
                String item = firstArr[i];
                if (secondArr.contains(item)) {
                    builder.append(item);
                    builder.append(",");
                }
            }
            if (builder.length() > 0) {
                System.out.println(builder.substring(0, builder.length() - 1));
            } else {
                System.out.println();
            }
        }
    }

} 
