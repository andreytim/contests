public class Main {

  public static final char[][] board = {
    { '#', '#', '#', '#', '#', '#' },
    { '#', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '#' },
    { '#', '.', '.', '.', '.', '#' },
    { '#', '#', '#', '#', '#', '#' }
  };

  private static int counter = 0;

  public static void makeStep(int i, int j) {
    if (i == 4 && j == 4) {
      counter++;
      return;
    }
    board[i][j] = '#';
    for (int x = -1; x < 2; x++) {
      for (int y = -1; y < 2; y++) {
        if ((x == 0 || y == 0) && board[i + x][j + y] != '#') {
          makeStep(i + x, j + y);
        }
      }
    }
    board[i][j] = '.';
  }

  public static void main(String[] args) {
    makeStep(1, 1);
    System.out.println(counter);
  }

}
