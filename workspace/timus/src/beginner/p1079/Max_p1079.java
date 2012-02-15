package beginner.p1079;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Method - DP.
 */
public class Max_p1079 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Max_p1079()).start();
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
		int[] seq = new int[100000]; // main sequence
		seq[0] = 0;
		seq[1] = 1;
		for (int i = 2; i < seq.length; i++) {
			if ((i & 1) != 0) {
				seq[i] = seq[(i-1)/2] + seq[(i-1)/2 + 1]; 
			} else {
				seq[i] = seq[i/2];
			}
		}
		int[] max = new int[100000]; // maximums
		max[0] = 0;
		for (int i = 1; i < max.length; i++) {
			max[i] = Math.max(max[i-1], seq[i]);
		}
		int N = nextInt();
		while (N != 0) {
			out.println(max[N]);
			N = nextInt();
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
