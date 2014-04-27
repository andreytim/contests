import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

public class Main {

  public static boolean areFriends(String w1, String w2) {
    boolean friends = false;
    if (Math.abs(w1.length() - w2.length()) <= 1 && (
          w1.charAt(0) == w2.charAt(0) || w1.charAt(w1.length()-1) == w2.charAt(w2.length() - 1))) {
      int[][] levDM = new int[w1.length() + 1][w2.length() + 1];
      for (int i = 0; i <= w1.length(); i++) {
        for (int j = 0; j <= w2.length(); j++) {
          if (i == 0 || j == 0) {
            levDM[i][j] = Math.max(i, j);
          } else if (w1.charAt(i - 1) == w2.charAt(j - 1)) {
            levDM[i][j] = levDM[i - 1][j - 1];
          } else {
            levDM[i][j] = Math.min(levDM[i - 1][j], levDM[i][j - 1]);
            levDM[i][j] = Math.min(levDM[i - 1][j - 1], levDM[i][j]) + 1;
          }
        }
      }
      friends = levDM[w1.length()][w2.length()] == 1 ? true : false;
    }
    return friends;
  }

  public static Set<String> bfs(String word, Map<String, Set<String>> friendsGraph) {
    Set<String> visited = new HashSet<String>();
    Deque<String> queue = new LinkedList<String>();
    queue.add(word);
    while (!queue.isEmpty()) {
      String next = queue.removeFirst();
      visited.add(next);
      if (!friendsGraph.containsKey(next)) System.out.println(next);
      for (String f : friendsGraph.get(next)) {
        if (!visited.contains(f)) {
          queue.addLast(f);
        }
      }
    }
    return visited;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line = reader.readLine();
    List<String> testCases = new LinkedList<String>();
    while ((line != null && !line.equals("END OF INPUT"))) {
      testCases.add(line);
      line = reader.readLine();
    }
    
    Map<String, Set<String>> friendsGraph = new HashMap<String, Set<String>>();
    while ((line = reader.readLine()) != null) {
      friendsGraph.put(line, new HashSet<String>());
      for (String word : friendsGraph.keySet()) {
        if (areFriends(line, word)) {
          friendsGraph.get(line).add(word);
          friendsGraph.get(word).add(line);
        }
      }
    }

    for (String tc : testCases) {
      System.out.println(bfs(tc, friendsGraph).size());
    }
  }

}
