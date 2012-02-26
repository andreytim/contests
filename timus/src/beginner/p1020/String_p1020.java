package beginner.p1020;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class String_p1020 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new String_p1020()).start();
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
		double length = 2*Math.PI*nextDouble();
		double startX = nextDouble();
		double startY = nextDouble();
		
		double prevX = startX;
		double prevY = startY;
		
		for (int i = 0; i < N-1; i++) {
			double currX = nextDouble();
			double currY = nextDouble();
			length += Math.sqrt(Math.pow(prevX - currX, 2) + Math.pow(prevY - currY, 2));
			prevX = currX;
			prevY = currY;
		}
		length += Math.sqrt(Math.pow(prevX - startX, 2) + Math.pow(prevY - startY, 2));
		out.printf("%1$.2f",length);
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
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
