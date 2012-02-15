package beginner.p1044;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Method - DP.
 */
public class Luckies_1044 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Luckies_1044()).start();
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
		int N = nextInt()/2;
		int maxSum = 9*N;
		int[][] calc = new int[N+1][maxSum+1];
		
		//fill
		for (int i = 0; i <= N; i++) {
			Arrays.fill(calc[i], 0);
		}
		calc[0][0] = 1;
		
		//calculate matrix
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= maxSum; j++) {
				int sum = 0;
				for (int k = Math.max(j-9, 0); k <= j; k++) {
					sum += calc[i-1][k];
				}
				calc[i][j] = sum;
			}
		}
		
		//calculate number
		int num = 0;
		for (int i = 0; i <= maxSum; i++) {
			num += Math.pow(calc[N][i], 2);
		}
		
		out.print(num);
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