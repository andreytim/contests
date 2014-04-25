import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  private static final char[][] board = {
    { '#', '#', '#', '#', '#', '#' },
    { '#', 'A', 'B', 'C', 'E', '#' },
    { '#', 'S', 'F', 'C', 'S', '#' },
    { '#', 'A', 'D', 'E', 'E', '#' },
    { '#', '#', '#', '#', '#', '#' }
  };

  private static void printBoard() {
    System.out.println("Board:\n");
    for (int i = 1; i < board.length - 1; i++) {
      for (int j = 1; j < board[0].length - 1; j++) {
        System.out.print(board[i][j]);
      }
      System.out.println();
    }
    System.out.println("----\n");
  }

  private static boolean checkState(String word, int iWord, int ib, int jb) {
    if (iWord == word.length()) {
      return true;
    }
    boolean result = false;
    char tmp = board[ib][jb];
    board[ib][jb] = '#';
    if (word.charAt(iWord) == board[ib + 1][jb]) {
      result = checkState(word, iWord + 1, ib + 1, jb);
    } 
    if (!result && word.charAt(iWord) == board[ib - 1][jb]) {
      result = checkState(word, iWord + 1, ib - 1, jb);
    } 
    if (!result && word.charAt(iWord) == board[ib][jb + 1]) {
      result = checkState(word, iWord + 1, ib, jb + 1);
    } 
    if (!result && word.charAt(iWord) == board[ib][jb - 1]) {
      result = checkState(word, iWord + 1, ib, jb - 1);
    }
    board[ib][jb] = tmp;
    return result;
  }

  private static boolean check(String word) {
    if (word.length() > 0) {
      for (int i = 1; i < board.length - 1; i++) {
        for (int j = 1; j < board[0].length - 1; j++) {
          if (board[i][j] == word.charAt(0) && checkState(word, 1, i, j)) {
            return true; 
          }
        }
      }
    }
    return false;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String word;
    while ((word = reader.readLine()) != null) {
      System.out.println(check(word) ? "True" : "False");
    }
  }

}
