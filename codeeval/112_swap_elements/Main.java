import java.io.BufferedReader;
import java.io.FileReader;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] arr = line.split(" : ");
            String[] list = arr[0].split(" ");
            for (String cmnd : arr[1].trim().split(", ")) {
                String[] coords = cmnd.split("-");
                String x = list[Integer.valueOf(coords[0])];
                list[Integer.valueOf(coords[0])] = list[Integer.valueOf(coords[1])];
                list[Integer.valueOf(coords[1])] = x;
            }
            for (String str : list) {
                System.out.print(str + " ");
            }
            System.out.println();
        }
    }

}
