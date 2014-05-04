import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.List;
import java.util.LinkedList;

public class Main {

  private static class Building implements Comparable<Building> {

    private static int idxCounter = 0;

    public final int left;
    public final int right;
    public final int height;
    public final int idx = idxCounter++;

    public Building(int left, int right, int height) {
      this.left = left;
      this.right = right;
      this.height = height;
    }

    @Override public int compareTo(Building other) {
      return other.height - height;
    }

    @Override public String toString() {
      return String.format("Building[%d,%d]{%d}", left, right, height);
    } 

    public static Building valueOf(String str) {
      str = str.substring(1, str.length() - 1);
      String[] strArr = str.split(",");
      return new Building(Integer.parseInt(strArr[0]), 
          Integer.parseInt(strArr[2]), Integer.parseInt(strArr[1]));
    }
  }

  private static final int MAX_B = 1000;

  private static List<Integer> buildSkyline(Map<Integer, List<Building>> city) {
    Queue<Building> heights = new PriorityQueue<Building>();
    boolean[] active = new boolean[MAX_B+1];    
    List<Integer> skyline = new LinkedList<Integer>();
    int currHeight = 0;
    for (Integer p : city.keySet()) {
      for (Building b : city.get(p)) {
        if (p.intValue() == b.left) {
          heights.offer(b);
          active[b.idx] = true;
        } else {
          active[b.idx] = false;
          if (b.height == heights.peek().height) {
            while (!heights.isEmpty() && !active[heights.peek().idx]) {
              heights.poll();
            }
          }
        }
      }
      if (heights.isEmpty()) {
        skyline.add(p);
        skyline.add(0);
        currHeight = 0;
      } else if (currHeight != heights.peek().height) {
        skyline.add(p);
        skyline.add(heights.peek().height);
        currHeight = heights.peek().height;
      }
      //System.out.printf("Point %d. Heights: %s; Skyline: %s\n", 
      //    p, heights, skyline);
   }
    return skyline;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] bStr = line.split(";");
      Map<Integer, List<Building>> city = 
          new TreeMap<Integer, List<Building>>();
      for (String s : bStr) {
        Building b = Building.valueOf(s);
        if (!city.containsKey(b.left)) {
          city.put(b.left, new LinkedList<Building>());
        }
        city.get(b.left).add(b);
        if (!city.containsKey(b.right)) {
          city.put(b.right, new LinkedList<Building>());
        }
        city.get(b.right).add(b);
      }
      List<Integer> skyline = buildSkyline(city);
      for (Integer p : skyline) {
        System.out.print(p + " ");
      }
      System.out.println();
    }
  }

}
