package beginner.p1149;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Method:
 * 1. Generating N "sin"-strings - DP.
 * 2. Forming end result - simple iteration.
 */
public class Sin_p1149 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Sin_p1149()).start();
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
		int N = nextInt();
		String[] as = generateAs(N);
		String str = "";
		for (int i = 0; i < N; i++) {
			str = "(" + str + as[i] + "+" + (N-i) + ")";
		}
		out.print(str.substring(1, str.length()-1));
	}

	private String[] generateAs(int N) {
		String[] result = new String[N];
		result[0] = "sin(1)";
		for (int i = 1; i < N; i++) {
			String prev = result[i-1];
			int pasteIdx = prev.length() - i;
			String sign = ((i & 1) == 0) ? "+" : "-";
			result[i] = prev.substring(0,pasteIdx) + sign + "sin(" + (i+1) + ")" + prev.substring(pasteIdx);
		}
		return result;
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
