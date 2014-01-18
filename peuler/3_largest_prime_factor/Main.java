import java.util.Arrays;
import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Wrong arguments! Usage: java Main <long>");
        }
        long n = Long.parseLong(args[0]), curr = 3;
        long res = curr;
        while (n >= curr) {
            if (n % curr == 0) {
                res = curr;
                n /= curr;
            } else {
                curr += 2;
            }
        }
        System.out.println("Largest prime factor: " + res);
    }

}
