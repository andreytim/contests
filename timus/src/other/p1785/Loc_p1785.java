package other.p1785;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Loc_p1785 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Loc_p1785()).start();
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
		Map<Integer, String> loc = new HashMap<Integer, String>();
		for (int i = 1; i < 2001; i++) {
			if (i >= 1 && i <= 4) {
				loc.put(i, "few");
			} else if (i >= 5 && i <= 9) {
				loc.put(i, "several");
			} else if (i >= 10 && i <= 19) {
				loc.put(i, "pack");
			} else if (i >= 20 && i <= 49) {
				loc.put(i, "lots");
			} else if (i >= 50 && i <= 99) {
				loc.put(i, "horde");
			} else if (i >= 100 && i <= 249) {
				loc.put(i, "throng");
			} else if (i >= 250 && i <= 499) {
				loc.put(i, "swarm");
			} else if (i >= 500 && i <= 999) {
				loc.put(i, "zounds");
			} else if (i >= 1000) {
				loc.put(i, "legion");
			}
		}
		
		int N = nextInt();
		out.print(loc.get(N));
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
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
