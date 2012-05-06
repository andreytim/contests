package other.p1567;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Sms_p1567 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Sms_p1567()).start();
	}

	@Override
	public void run() {
		try {
			boolean oj = System.getProperty("ONLINE_JUDGE") != null;
			if (oj) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(new OutputStreamWriter(System.out));
			} else {
				in = new BufferedReader(new FileReader("input.txt"));
				out = new PrintWriter(new OutputStreamWriter(System.out));
			}
			solve();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			if (out != null) {
				out.flush();
				out.close();
			}
		}
	}

	private void solve() throws IOException {
		int[] prices = new int[255];
		prices['a'] = 1; prices['b'] = 2; prices['c'] = 3;
		prices['d'] = 1; prices['e'] = 2; prices['f'] = 3;
		prices['g'] = 1; prices['h'] = 2; prices['i'] = 3;
		prices['j'] = 1; prices['k'] = 2; prices['l'] = 3;
		prices['m'] = 1; prices['n'] = 2; prices['o'] = 3;
		prices['p'] = 1; prices['q'] = 2; prices['r'] = 3;
		prices['s'] = 1; prices['t'] = 2; prices['u'] = 3;
		prices['v'] = 1; prices['w'] = 2; prices['x'] = 3;
		prices['y'] = 1; prices['z'] = 2; prices['!'] = 3;
		prices['.'] = 1; prices[','] = 2; prices[' '] = 1;
		
		int sum = 0, c;
		while ((c = in.read()) != -1) {
			sum += prices[c];
		}
		out.print(sum);
	}
}
