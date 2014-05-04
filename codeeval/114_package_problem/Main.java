import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.Deque;
import java.util.LinkedList;

public class Main {

  private static class Item {
    public final int idx;
    public final int weight;
    public final int cost;

    public Item(int idx, double weight, int cost) {
      this.idx = idx;
      this.weight = (int) (weight * 100.0);
      this.cost = cost;
    }

    public static Item valueOf(String str) {
      str = str.substring(1, str.length() - 1); // remove parentheses
      String[] arr = str.split(",");
      return new Item(Integer.parseInt(arr[0]), Double.parseDouble(arr[1]),
          Integer.parseInt(arr[2].substring(1)));
    }

    @Override public String toString() {
      return String.valueOf(idx);
    }
  }

  public static void printM(int[][] m) {
    for (int i = 0; i < m[0].length; i++) {
      System.out.printf("weight %d:\t", i);
      for (int j = 0; j < m.length; j++) {
        System.out.printf("%d\t", m[j][i]);
      }
      System.out.println();
    }
  }

  public static Deque<Item> maxCostPack(Item[] items, int W) {
    int[][] dm = new int[items.length+1][W+1];
    for (int i = 1; i <= items.length; i++) {
      for (int w = 1; w <= W; w++) {
        if (items[i-1].weight > w) {
          dm[i][w] = dm[i-1][w];
        } else {
          dm[i][w] = Math.max(dm[i-1][w], 
              dm[i-1][w - items[i-1].weight] + items[i-1].cost);
        }
      }
    }
    Deque<Item> pack = new LinkedList<Item>();
    int w = W;
    while (w > 0 && dm[items.length][w] == dm[items.length][w-1]) w--;
    for (int i = items.length; dm[i][w] > 0; i--) {
      if (dm[i][w] > dm[i-1][w]) {
        pack.push(items[i-1]);
        w = w - items[i-1].weight;
      }
    }
    //printM(dm);
    //System.out.printf("Total cost = %d; ", dm[items.length][W-1]);
    return pack;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      if (!line.equals("")) {
        String[] arr = line.split(" : ");
        int W = Integer.parseInt(arr[0]) * 100;
        String[] itemsStr = arr[1].split(" ");
        Item[] items = new Item[itemsStr.length];
        for (int i = 0; i < items.length; i++) {
          items[i] = Item.valueOf(itemsStr[i]);
        }
        Deque<Item> pack = maxCostPack(items, W);
        if (pack.isEmpty()) System.out.print("-");
        else {
          int i = 0;
          for (Item item : pack) {
            if (i++ > 0) System.out.print(",");
            System.out.print(item);
          }
        }
        System.out.println();
      }
    }
  }

}
