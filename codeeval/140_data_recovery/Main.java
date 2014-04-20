import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] parts = line.split(";");
      String[] words = parts[0].split(" ");
      String[] indices = parts[1].split(" ");
      String[] newOrder = new String[words.length];
      for (int i = 0; i < indices.length; i++) {
        newOrder[Integer.parseInt(indices[i]) - 1] = words[i];
      }
      for (int i = 0; i < words.length; i++) {
        System.out.print((newOrder[i] != null) ? newOrder[i] : words[words.length - 1]);
        System.out.print(" ");
      }
      System.out.println();
    }
  }
}
