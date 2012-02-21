package beginner.p1209;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TenPow_p1209 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new TenPow_p1209()).start();
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
		
		byte[] outArr = new byte[N];
		for (int i = 0; i < N; i++) {
			long idx = nextInt();
			double f = Math.sqrt(8 * idx - 7);
			if (f - (int) f == 0) {
				outArr[i] = 1;
			} else {
				outArr[i] = 0;
			}
		}
		
		for (int i = 0; i < outArr.length; i++) {
			out.print(outArr[i]);
			out.print(' ');
		}
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
