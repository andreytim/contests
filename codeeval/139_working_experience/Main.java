import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Main {
  
  public static Map<String, Integer> MONTHS = new HashMap<>();
  static {
    MONTHS.put("Jan", Integer.valueOf(0));
    MONTHS.put("Feb", Integer.valueOf(1));
    MONTHS.put("Mar", Integer.valueOf(2));
    MONTHS.put("Apr", Integer.valueOf(3));
    MONTHS.put("May", Integer.valueOf(4));
    MONTHS.put("Jun", Integer.valueOf(5));
    MONTHS.put("Jul", Integer.valueOf(6));
    MONTHS.put("Aug", Integer.valueOf(7));
    MONTHS.put("Sep", Integer.valueOf(8));
    MONTHS.put("Oct", Integer.valueOf(9));
    MONTHS.put("Nov", Integer.valueOf(10));
    MONTHS.put("Dec", Integer.valueOf(11));
  }
  
  private static int[] parseInterval(String strInterval) {
    int[] interval = new int[2];
    interval[0] = MONTHS.get(strInterval.substring(0, 3)) 
        + (Integer.parseInt(strInterval.substring(4, 8)) - 1990) * 12;
    interval[1] = MONTHS.get(strInterval.substring(9, 12)) 
        + (Integer.parseInt(strInterval.substring(13, 17)) - 1990) * 12;
    return interval;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] strIntervals = line.split("; ");
      int[] months = new int[372];
      for (String strInterval : strIntervals) {
        int[] interval = parseInterval(strInterval);
        for (int i = interval[0]; i <= interval[1]; i++) {
          months[i] = 1;
        }
      }
      int totalMonths = 0;
      for (int m : months) totalMonths += m;
      System.out.println(totalMonths / 12);
    }
  }
}
