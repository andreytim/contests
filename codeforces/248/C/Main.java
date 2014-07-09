import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static long findNumberOfTurns(int[] pages, int n) {
    if (pages.length == 1) return 0;
    long[] counts = new long[n+1];
    for (int i = 1; i < pages.length; i++) {
      if (i < pages.length-1 && (pages[i] - pages[i-1])*(pages[i] - pages[i+1]) < 0) {
        counts[pages[i]] += Math.abs(pages[i] - pages[i-1]);
        counts[pages[i]] += Math.abs(pages[i] - pages[i+1]);
      } else if ((pages[i-1] - pages[i])*(pages[i-1] - pages[i-2]) > 0) {
        counts[pages[i]] += Math.abs(pages[i] - pages[i-1]);
      }
    }
    int max = pages[0];
    for (int i = 1; i < pages.length; i++) {
      if (counts[pages[i]] > counts[max]) {
          max = pages[i];
      }
    }
    for (int i = 0; i < pages.length; i++) {
      if (pages[i] == max) {
        pages[i] = (i > 0 ? pages[i-1] : pages[i+1]);
      }
    }
    System.out.println(max + ":" + Arrays.toString(pages));
    long res = 0;
    for (int i = 1; i < pages.length; i++) {
      res += Math.abs(pages[i] - pages[i-1]);
    }
    return res;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] strArr = line.split(" ");
      int n = Integer.parseInt(strArr[0]);
      int m = Integer.parseInt(strArr[1]);
      strArr = reader.readLine().split(" ");
      int[] pages = new int[m];
      for (int i = 0; i < pages.length; i++) {
        pages[i] = Integer.parseInt(strArr[i]);
      }
      System.out.println(findNumberOfTurns(pages, n));
    }
  }

}
