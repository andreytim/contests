import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

  private static int MAX_WIDTH = 12;
  private static int MAX_HEIGHT = 50;

  private static void printTrack(char[][] track, int h, int w) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        System.out.print(track[i][j]);
      }
      System.out.println();
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    char[][] raceTrack = new char[MAX_HEIGHT][MAX_WIDTH];
    int width = 0, height = 0, prevPassage = -1;
    while ((line = reader.readLine()) != null) {
      width = 0;
      int cIdx = -1, uscrIdx = -1;
      for (char ch : line.toCharArray()) {
        raceTrack[height][width] = ch;
        if (ch == 'C') {
          cIdx = width;
        } else if (ch == '_') {
          uscrIdx = width;
        }
        width++;                
      }
      int passage = (cIdx == -1) ? uscrIdx : cIdx;
      if (prevPassage == -1 || prevPassage == passage) {
        raceTrack[height][passage] = '|';
      } else if (prevPassage < passage) {
        raceTrack[height][passage] = '\\';
      } else {
        raceTrack[height][passage] = '/';
      }
      prevPassage = passage;
      height++;
    }
    printTrack(raceTrack, height, width);
  }
}
