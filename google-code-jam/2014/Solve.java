import java.io.*;
import java.util.*;
import java.math.*;

public class Solve {

  private static String solve() {
    return "";
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line = reader.readLine();
    int T = Integer.parseInt(line);
    for (int i = 0; i < T; i++) {
      // read input
      System.out.printf("Case #%d: %s\n", i + 1, solve());
    }
  }

}
