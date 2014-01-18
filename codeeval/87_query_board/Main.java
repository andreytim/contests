import java.io.BufferedReader;
import java.io.FileReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        int[][] board = new int[256][256];
        while ((line = reader.readLine()) != null) {
            String[] arr = line.split(" ");
            int idx = Integer.parseInt(arr[1]);
            if (arr.length > 2) {
                int x = Integer.parseInt(arr[2]);
                if (arr[0].equals("SetCol")) {
                    for (int i = 0; i < 256; i++) board[i][idx] = x;
                } else if (arr[0].equals("SetRow")) {
                    for (int i = 0; i < 256; i++) board[idx][i] = x;
                }    
            } else {
                if (arr[0].equals("QueryCol")) {
                    int sum = 0;
                    for (int i = 0; i < 256; i++) sum += board[i][idx];
                    System.out.println(sum);
                } else if (arr[0].equals("QueryRow")) {
                    int sum = 0;
                    for (int i = 0; i < 256; i++) sum += board[idx][i];
                    System.out.println(sum);
                }
            }
        }
    }

}
