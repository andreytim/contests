import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Arrays;

public class Main {
  
  private static class NGramStats {
 
    public static class Item implements Comparable<Item> {
      public final String word;
      public final double score;
      public Item(String word, double score) { 
        this.word = word;
        this.score = score; 
      }
      @Override public int compareTo(Item other) {
        if (score == other.score) {
          return word.compareTo(other.word);
        }
        return (int)(other.score*1000) - (int)(score*1000);
      }
    }

    private static final String[] TEXT = new String(
        "Mary had a little lamb its fleece was white as snow " +
        "And everywhere that Mary went the lamb was sure to go " + 
        "It followed her to school one day which was against the rule " +
        "It made the children laugh and play to see a lamb at school " +
        "And so the teacher turned it out but still it lingered near " +
        "And waited patiently about till Mary did appear " +
        "Why does the lamb love Mary so the eager children cry " +
        "Why Mary loves the lamb you know the teacher did reply"
        ).split(" ");
 
    private final int n;
    
    public NGramStats(int n) {
      this.n = n;
    }
  
    public Set<Item> getProbs(String ngramString) {
      Map<String, Integer> counts = new HashMap<>();
      double total = 0.0;
      String[] ngram = clean(ngramString).split(" ");
      int i = 0;
      while (i < TEXT.length) {
        int k = 0;
        while (i + k < TEXT.length && k < ngram.length && 
            TEXT[i + k].equals(ngram[k])) k++;
        if (k == ngram.length) {
          i += k;
          total += 1;
          if (i < TEXT.length) {
            String word = TEXT[i];
            if (!counts.containsKey(word)) {
              counts.put(word, 0);
            }
            counts.put(word, counts.get(word) + 1);
          }
        } else {
          i++;
        }
      }
      Set<Item> result = new TreeSet<Item>();
      for (Entry<String, Integer> count : counts.entrySet()) {
        result.add(new Item(count.getKey(), count.getValue()/total));
      }
      return result;
    }

    private String clean(String str) {
      char[] arr = str.toCharArray();
      StringBuilder builder = new StringBuilder();
      for (char ch : arr) {
        if (ch == ' ' || (ch >= 'a' && ch <= 'z')
            || (ch >= 'A' && ch <= 'Z')) {
          builder.append(ch);
        }
      }
      return builder.toString();
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] arrStr = line.split(",");
      int n = Integer.parseInt(arrStr[0]);
      StringBuilder builder = new StringBuilder();
      for (NGramStats.Item item : new NGramStats(n).getProbs(arrStr[1])) {
        builder.append(item.word);
        builder.append(",");
        builder.append(String.format("%.3f;", item.score));
      }
      System.out.println(builder.substring(0, builder.length() - 1));
    }
  }

}
