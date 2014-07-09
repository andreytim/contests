import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  private static long[] sums;
  private static long[] sortedSums;

  public static long[] precalcSums(long[] costs) {
    long[] res = new long[costs.length];
    res[0] = costs[0];
    for (int i = 1; i < costs.length; i++) {
      res[i] = res[i-1] + costs[i];
    }
    return res;
  }

  public static long calcRangeSum(long[] sums, int l, int r) {
    long res = sums[r];
    if (l > 0) {
      res -= sums[l-1];
    }
    return res;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = reader.readLine()) != null) {
      int N = Integer.parseInt(line);
      long[] costs = new long[N];
      int i = 0;
      for (String cStr : reader.readLine().split(" ")) {
        costs[i++] = Long.parseLong(cStr);
      }
      sums = precalcSums(costs);
      Arrays.sort(costs);
      sortedSums = precalcSums(costs);
      int m = Integer.parseInt(reader.readLine());
      for (i = 0; i < m; i++) {
        String[] strArr = reader.readLine().split(" ");
        System.out.println(calcRangeSum(Integer.parseInt(strArr[0]) == 1 ? sums : sortedSums, 
                    Integer.parseInt(strArr[1])-1, Integer.parseInt(strArr[2])-1));
      }
    }
  }

}
