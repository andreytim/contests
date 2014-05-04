public class Main {

  private static int sumOfDigits(int n) {
    int res = 0;
    while (n > 0) {
      res += n % 10;
      n /= 10;
    }
    return res;
  }

  private static int MAX = 300;
  private static int THRESHOLD = 19;
  private static byte[][] grid = new byte[MAX][MAX];
  private static int total = 0;

  private static void walk(int x, int y) {
    grid[x][y] = 1;
    if (sumOfDigits(x) + sumOfDigits(y) <= THRESHOLD) {
      if (x > 0) total += 1;
      grid[x][y] = 2;
      if (grid[x+1][y] == 0) walk(x+1, y);
      if (grid[x][y+1] == 0) walk(x, y+1);
      if (x > 0 && grid[x-1][y] == 0) walk(x-1, y);
      if (y > 0 && grid[x][y-1] == 0) walk(x, y-1);
    }
  }

  private static void printGrid() {
    for (int i = 0; i < grid.length; i++) {
      System.out.print(i + ":\t");
      for (int j = 0; j < grid[0].length; j++) {
        System.out.print(grid[i][j]);
      }
      System.out.println();
    }
  }

  public static void main(String[] args) {
    walk(0, 0);
    System.out.println(total*4+1);
  }

}
