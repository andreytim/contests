import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

public class Main {
  
  private static boolean checkFriendship(String w1, String w2) {
    if (Math.abs(w1.length() - w2.length()) > 1) {
      return false;
    } else if (w1.length() == w2.length()) {
      for (int i = 0, countDiff = 0; i < w1.length(); i++) {
        if (w1.charAt(i) != w2.charAt(i)) countDiff++;
        if (countDiff > 1) return false;
      }
    } else {
      if (w1.length() < w2.length()) { 
        String tmp = w1;
        w1 = w2;
        w2 = tmp;
      }
      int i = 0, j = 0;
      while (j < w2.length() && (i - j) < 2) {
        if (w1.charAt(i) == w2.charAt(j)) {
          j++;
        }
        i++;
      }
      if (i - j > 1) return false;
    }
    return true;  
  }

  private static final Set<Set<String>> cache = new HashSet<Set<String>>();

  private static Set<String> bfsFriendsNetwork(String word, Set<String> words) {
    for (Set<String> s : cache) {
      if (s.contains(word)) {
        return s;
      }
    }
    Set<String> friends = new HashSet<String>();
    Set<String> visited = new HashSet<String>();
    Deque<String> queue = new LinkedList<String>();
    queue.add(word);
    visited.add(word);
    while (!queue.isEmpty()) {
      String curr = queue.removeFirst();
      for (String w : words) {
        if (!visited.contains(w)) { 
          if (checkFriendship(curr, w)) {
            friends.add(w);
            queue.addLast(w);
            visited.add(w);
          }
        }
      }
    }
    cache.add(friends);
    return friends;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line = reader.readLine();
    
    List<String> testCases = new LinkedList<String>();
    while ((line != null && !line.equals("END OF INPUT"))) {
      testCases.add(line);
      line = reader.readLine();
    }
    
    Set<String> words = new HashSet<String>();
    while ((line = reader.readLine()) != null) {
      words.add(line);
    }

    for (String tc : testCases) {
      System.out.println(bfsFriendsNetwork(tc, words).size() + 1);
    }
  }

}
