import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {

  private static class Point implements Comparable<Point> {    
    
    public final int x;
    public final int y;
    
    public Point(int x, int y) { this.x = x; this.y = y; }
    
    @Override public int compareTo(Point p) {
      return x - p.x;
    }

    @Override public String toString() {
      return String.format("Point[%d,%d]", x, y);
    }

    public double distance(Point p) {
      return Math.sqrt((double)(x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }

    public static Point valueOf(String line) {
      String[] pStr = line.split(" ");
      return new Point(Integer.valueOf(pStr[0]), Integer.valueOf(pStr[1]));
    }
  }

  public static final int DIST_THRESHOLD = 10000;

  public static double minDistanceBF(Point[] points, int i, int j) {
    double res = Double.MAX_VALUE;
    for (int i1 = i; i1 <= j; i1++) {
      for (int i2 = i1 + 1; i2 <= j; i2++) {
        res = Math.min(res, points[i1].distance(points[i2]));
      }
    }
    return res;
  }

  public static double minDistance(Point[] points, int i, int j) {
    if (j - i <= 2) { return minDistanceBF(points, i, j); }
    int mid = i + (j - i)/2;
    double d = Math.min(minDistance(points, i, mid), minDistance(points, mid + 1, j));
    int l = i, r = j;
    while (points[mid].x - points[l].x > d) l++;
    while (points[r].x - points[mid].x > d) r--;
    return Math.min(d, minDistanceBF(points, l, r));
  } 

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while (!(line = reader.readLine()).equals("0")) {
      int n = Integer.parseInt(line);
      Point[] points = new Point[n];
      for (int i = 0; i < n; i++) {
        line = reader.readLine();
        points[i] = Point.valueOf(line);
      }
      Arrays.sort(points);
      double dist = minDistance(points, 0, points.length - 1);
      System.out.println(dist >= DIST_THRESHOLD ? "INFINITY" : String.format("%.4f", dist));
    }
  }

}
