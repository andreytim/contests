import java.io.BufferedReader;
import java.io.FileReader;
import java.util.TreeMap;
import java.util.HashSet;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] arr = line.split(" ");
            HashSet<Integer> met = new HashSet<Integer>();
            TreeMap<Integer, Integer> uniques = new TreeMap<Integer, Integer>();
            for (int i = 0; i < arr.length; i++) {
                Integer number = Integer.valueOf(arr[i]);
                if (met.add(number)) { 
                    uniques.put(number, i + 1);
                } else {
                    uniques.remove(number);
                }
            }
            if (uniques.isEmpty()) {
                System.out.println("0");
            } else {
                System.out.println(uniques.firstEntry().getValue());
            }
        }
    }

}
