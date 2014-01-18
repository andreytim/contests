import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger n = new BigInteger("2").pow(1000);
        int result = 0;
        for (char ch : n.toString().toCharArray()) {
            result += ch - '0';
        }
        System.out.println(result);
    }    
}
