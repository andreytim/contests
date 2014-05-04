import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;

public class Main {

  private static final int MAX = 1000;
  private static final BigInteger[] PRE_CALCULATED = new BigInteger[MAX];

  private static void countWays() {
    PRE_CALCULATED[0] = BigInteger.ONE;
    PRE_CALCULATED[1] = BigInteger.valueOf(2);
    for (int i = 2; i < MAX; i++) {
      PRE_CALCULATED[i] = PRE_CALCULATED[i-1].add(PRE_CALCULATED[i-2]);
    }
  }

  public static void main(String[] args) throws IOException {
    countWays();
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    try {
      while ((line = reader.readLine()) != null) {
        int N = Integer.parseInt(line);
        System.out.println(PRE_CALCULATED[N-1].toString());
      }
    } finally {
      reader.close();
    }
  }

}
