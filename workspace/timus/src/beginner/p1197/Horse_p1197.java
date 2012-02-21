package beginner.p1197;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Method - head-on.
 */
public class Horse_p1197 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Horse_p1197()).start();
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
		int[][] attacks = new int[8][8];
		for (int i = 0; i < attacks.length; i++) {
			for (int j = 0; j < attacks.length; j++) {
				attacks[i][j] = checkAttacks(i,j);
			}
		}
		int N = nextInt();
		String str, res = "";
		for (int i = 0; i < N; i++) {
			str = nextString();
			res += attacks[str.charAt(0) - 'a'][str.charAt(1) - '1'] + "\n";
		}
		out.print(res);
	}

	private int checkAttacks(int i, int j) {
		int res = 0;
		if (i + 1 < 8 && j + 2 < 8) res++;
		if (i + 2 < 8 && j + 1 < 8) res++;
		if (i + 1 < 8 && j - 2 >= 0) res++;
		if (i + 2 < 8 && j - 1 >= 0) res++;
		if (i - 1 >= 0 && j + 2 < 8) res++;
		if (i - 2 >= 0 && j + 1 < 8) res++;
		if (i - 1 >= 0 && j - 2 >= 0) res++;
		if (i - 2 >= 0 && j - 1 >= 0) res++;
		return res;
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
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
