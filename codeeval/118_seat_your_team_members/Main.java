import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

  private static final Comparator<List<?>> SIZE_COMPARATOR = new Comparator<List<?>>() {
    @Override public int compare(List<?> s1, List<?> s2) {
      return s1.size() - s2.size();
    }
  };

  private static List<Integer> parseTeamMate(String line) {
    String offBrackets = line.substring(line.indexOf("[") + 1);
    List<Integer> result = new ArrayList<Integer>();
    for (String item : offBrackets.split(", ")) {
      result.add(Integer.valueOf(item));
    }
    return result;
  }

  public static boolean checkPossibility(int N, List<List<Integer>> teamMates) {
    return checkHelper(new boolean[N+1], teamMates, 0);
  }

  private static boolean checkHelper(boolean[] places, List<List<Integer>> mates, int currIdx) {
    if (currIdx == mates.size()) {
      return true;
    } else {
      List<Integer> variants = mates.get(currIdx);
      for (Integer pv : variants) {
        if (!places[pv]) {
          places[pv] = true;
          if (checkHelper(places, mates, currIdx + 1)) {
            return true;
          }
          places[pv] = false;
        }
      }
      return false;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] scSplitted = line.split(";");
      byte N = Byte.parseByte(scSplitted[0]);
      List<List<Integer>> teamMates = new ArrayList<List<Integer>>();
      Collections.sort(teamMates, SIZE_COMPARATOR);
      for (String strItem : scSplitted[1].substring(1, scSplitted[1].length()-1).split("], ")) {
        teamMates.add(parseTeamMate(strItem));
      }
      System.out.println(checkPossibility(N, teamMates) ? "Yes" : "No");
    }
  }

}
