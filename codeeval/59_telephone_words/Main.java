import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  private static final String[] MAPPING =
      new String[]{ "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

  private static void printRecursive(String line) {
    printRecursiveHelper(line.toCharArray(), 0, new StringBuilder());
    System.out.println();
  } 

  private static boolean notFirst = false;

  private static void printRecursiveHelper(char[] line, int i, StringBuilder buffer) {
    if (i == line.length) {
      if (notFirst) {
        System.out.print(",");
      } else {
        notFirst = true;
      }
      System.out.print(buffer.toString());
    } else {
      String cands = MAPPING[line[i] - '0'];
      for (int j = 0; j < cands.length(); j++) {
        buffer.append(cands.charAt(j));
        printRecursiveHelper(line, i+1, buffer);
        buffer.setLength(buffer.length() - 1);
      }
    }    
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      notFirst = false;
      printRecursive(line);
    }
  }

}
