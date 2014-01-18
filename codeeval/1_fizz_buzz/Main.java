import java.io.BufferedReader;
import java.io.FileReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] pars = line.split(" ");
            int f = Integer.parseInt(pars[0]), b = Integer.parseInt(pars[1]);
            int lim = Integer.parseInt(pars[2]);
            boolean[] fs = new boolean[lim + 1];
            for (int i = f; i <= lim; i += f) { fs[i] = true; }
            boolean[] bs = new boolean[lim + 1];
            for (int i = b; i <= lim; i += b) { bs[i] = true; }
            for (int i = 1; i <= lim; i++) {
                if (fs[i] && bs[i]) {
                    System.out.print("FB");
                } else if (fs[i]) {
                    System.out.print("F");
                } else if (bs[i]) {
                    System.out.print("B");
                } else {
                    System.out.print(i);
                }
                System.out.print(" ");
            }
            System.out.println();
        }
    }

}
