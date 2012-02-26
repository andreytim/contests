package beginner.p1005;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Method - BruteForce. 
 * DP is also possible but can't consider for now.
  */
public class Stones_1005 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Stones_1005()).start();
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
			out.flush();
			out.close();
		}
	}

	private void solve() throws IOException {
		int N = nextInt();
		int[] stones = new int[N];
		for (int i = 0; i < N; i++) {
			stones[i] = nextInt();
		}		
		long lim = 1 << N;
		int res = Integer.MAX_VALUE;
		for (int i = 0; i < lim; i++) {
			int k = i;
			int sumA = 0;
			int sumB = 0;
			for (int j = 0; j < N; j++) {
				if ((k & 1) != 0) {
					sumA += stones[j]; 
				} else {
					sumB += stones[j];
				}
				k >>= 1;
			}
			res = Math.min(res, Math.abs(sumB - sumA));
		}
		out.print(res);
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
}

