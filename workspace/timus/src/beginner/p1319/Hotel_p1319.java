package beginner.p1319;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Hotel_p1319 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Hotel_p1319()).start();
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
		int count = 1;
		int[][] res = new int[N][N];
		for (int shift = 1-N; shift < N; shift++) {
			for (int i = Math.max(shift, 0); i < Math.min(N, N + shift); i++) {
				int j = i - shift;
				res[i][j] = count++;
			}
		}
		
		for (int i = 0; i < res.length; i++) {
			for (int j = 0; j < res.length; j++) {
				out.print(res[i][j]);
				out.print(' ');
			}
			out.print('\n');
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
