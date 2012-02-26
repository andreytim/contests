package beginner.p1086;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Prime_p1086 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;
	long[] primes = new long[15000];
	
	public static void main(String... args) {
		new Thread(new Prime_p1086()).start();
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
		int[] in = new int[N];
		for (int i = 0; i < N; i++) {
			in[i] = nextInt();
		}
		
		primes[0] = 2;
		int count = 1;
		long curr = 2;
		while (count < 15000) {
			curr++;
			if (checkPrime(curr)) {
				primes[count++] = curr;
			}
		}
		
		for (int i = 0; i < N; i++) {
			out.println(primes[in[i]-1]);
		}
	}

	private boolean checkPrime(long curr) {
		if ((curr & 1) == 0) {
			return false;
		}
		int i = 1;
		while (primes[i] != 0 && primes[i]*primes[i] <= curr) {
			if (curr % primes[i++] == 0) {
				return false;
			}
		}
		return true;
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