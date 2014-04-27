import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  public static int countDS(String word, String seq) {
    char[] warr = word.toCharArray();
    char[] sarr = seq.toCharArray();
    int[][] dm = new int[warr.length][sarr.length];
    dm[0][0] = warr[0] == sarr[0] ? 1 : 0;
    for (int i = 1; i < sarr.length; i++) {
      dm[0][i] = 0;
    }
    for (int i = 1; i < warr.length; i++) {
      dm[i][0] = sarr[0] == warr[i] ? dm[i-1][0] + 1 : dm[i - 1][0];
    }
    for (int i = 1; i < warr.length; i++) {
      for (int j = 1; j < sarr.length; j++) {
        dm[i][j] = warr[i] == sarr[j] ? dm[i-1][j-1] + dm[i-1][j] : dm[i-1][j];
      }
    }
    return dm[warr.length-1][sarr.length-1];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] seqs = line.split(",");
      System.out.println(countDS(seqs[0], seqs[1]));
    }
  }

}
