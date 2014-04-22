import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
  
  private static int[] parseArray(String commaSeparated) {
    String[] arrStr = commaSeparated.split(",");
    int[] result = new int[arrStr.length];
    for (int i = 0; i < result.length; i++) {
      result[i] = Integer.parseInt(arrStr[i]);
    }
    return result;
  }

  private static int numberOfBlocks(int[] hor, int[] ver) {
    double slope = (double) ver[ver.length - 1] / hor[hor.length - 1];
    int total = 0;
    for (int i = 1; i < hor.length; i++) {
      for (int j = 1; j < ver.length; j++) {
        if (ver[j] > slope * hor[i - 1] && ver[j - 1] < slope * hor [i]) {
          total++;
        }
      }
    }
    return total;
  }
 
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] parts = line.split(" ");
      System.out.println(numberOfBlocks(
          parseArray(parts[0].substring(1, parts[0].length() - 1)),
          parseArray(parts[1].substring(1, parts[1].length() - 1))
      ));  
    }
  }

}
