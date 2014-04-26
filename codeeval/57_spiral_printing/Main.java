import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] argsArr = line.split(";");
      int N = Integer.parseInt(argsArr[0]);
      int M = Integer.parseInt(argsArr[1]);
      if (N > 0 && M > 0) {

        // input
        String[][] matrix = new String[N][M];
        int i = 0, j = 0;
        for (String str : argsArr[2].split(" ")) {
           matrix[i][j] = str;
           j = (j + 1) % M;
           if (j == 0) i += 1;
        }

        // First row
        System.out.print(matrix[0][0]);
        for (i = 1; i < M; i++) {
          System.out.print(" " + matrix[0][i]);
        }

        // Spiral
        int n = N - 1;
        int m = M - 1;
        boolean rd = true;
        i = 0; j = m;
        int count = N * M - M;
        while (count > 0) {
          if (rd) {
            i += 1;
            for (int k = 0; k < n; k++) System.out.print(" " + matrix[k + i][j]);
            i += n - 1;
            j -= 1;
            for (int k = 0; k < m; k++) System.out.print(" " + matrix[i][j - k]);
            j -= m - 1;
          } else {
            i -= 1;
            for (int k = 0; k < n; k++) System.out.print(" " + matrix[i - k][j]);
            i -= n - 1;
            j += 1;
            for (int k = 0; k < m; k++) System.out.print(" " + matrix[i][k + j]);
            j += m - 1;
          }
          count -= n + m;
          n -= 1;
          m -= 1;
          rd = !rd;
        }
      }

      System.out.println();
    }
  }

}
