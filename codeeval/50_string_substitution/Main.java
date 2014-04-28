import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  private static String substitute(String str, String[] args) {
    boolean[] visited = new boolean[str.length()];
    String[] res = new String[str.length()];
    for (int i = 0; i < args.length; i += 2) {
      String sstr = args[i];
      String rstr = args[i+1];
      int idx = str.indexOf(sstr);
      while (idx != -1) {
        boolean isVisited = visited[idx];
        int l = idx;
        while (!isVisited && ++l < idx + sstr.length()) isVisited = visited[l];
        if (!isVisited) {
          for (l = idx; l < idx + sstr.length(); l++) visited[l] = true;
          res[idx] = rstr;
        }
        idx = str.indexOf(sstr, idx + 1);
      }
    }
    StringBuilder resb = new StringBuilder();
    for (int i = 0; i < str.length(); i++) {
      if (res[i] != null) {
        resb.append(res[i]);
      } else if (!visited[i]) {
        resb.append(str.charAt(i));
      }
    }
    return resb.toString();
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] strArr = line.split(";");
      System.out.println(substitute(strArr[0], strArr[1].split(",")));
    }
  }

}
