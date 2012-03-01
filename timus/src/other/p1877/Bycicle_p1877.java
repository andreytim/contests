package other.p1877;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Bycicle_p1877 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Bycicle_p1877()).start();
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
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
		int first, second;
		first = Integer.parseInt(nextString());
		second = Integer.parseInt(nextString());
		if ((first & 1) == 0 || (second & 1) != 0) {
			out.print("yes");
		} else {
			out.print("no");
		}
	}

	private String nextString() throws IOException {
		return nextToken();
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();
			if (line != null) {
				st = new StringTokenizer(line);
			} else {
				return null;
			}
		}
		return st.nextToken();
	}
}