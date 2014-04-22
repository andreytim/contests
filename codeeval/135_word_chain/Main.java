import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class Main {

  public static int countMaxCombination(Map<Character, Set<String>> words, char letter) {
    int maxCount = -1;
    if (words.containsKey(letter) && !words.get(letter).isEmpty()) {
      Set<String> words4letter = new HashSet<>();
      words4letter.addAll(words.get(letter));
      // System.out.println(letter + ": " + words4letter);
      for (String word : words4letter) {
        words.get(letter).remove(word);
        maxCount = Math.max(maxCount, countMaxCombination(words, word.charAt(word.length() - 1)));
        words.get(letter).add(word);
      }
    }
    return maxCount + 1;
  } 

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0])); 
    String line;
    while ((line = reader.readLine()) != null) {
      String[] words = line.split(",");
      Map<Character, Set<String>> l2words = new HashMap<>();
      for (String w : words) {
        if (!l2words.containsKey(w.charAt(0))) {
          l2words.put(w.charAt(0), new HashSet<String>());
        }
        l2words.get(w.charAt(0)).add(w);
      }
      int maxCount = 0;
      for (Character letter : l2words.keySet()) {
        maxCount = Math.max(maxCount, countMaxCombination(l2words, letter));
      }
      System.out.println(maxCount == 1 ? "None" : "" + maxCount);
    } 
  }

}
