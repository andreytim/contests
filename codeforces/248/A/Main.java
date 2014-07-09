import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

  public static boolean check(int ones, int twos, int W) {
    if (W < 100) {
      return false;
    } else if ((W == 100 && ones > 0) || W == 200 && twos > 0) {
      return true;
    }
    System.out.println(ones + ":" + twos + ":" + W);
    return (ones > 0 && check(ones - 1, twos, W - 100)) ||
        (twos > 0 && check(ones, twos - 1, W - 200));
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = reader.readLine()) != null) {
      int N = Integer.parseInt(line);
      int ones = 0, twos = 0;
      for (String aStr : reader.readLine().split(" ")) {
        int apple = Integer.parseInt(aStr);
        if (apple == 200) {
          twos++;
        } else {
          ones++;
        }
      }
      System.out.println(check(ones, twos, (ones*100 + twos*200) / 2) ? "YES" : "NO");
    }
  }

}
