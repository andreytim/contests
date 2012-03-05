package other.p1880;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class PsychUp_p1880 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new PsychUp_p1880()).start();
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
		int n, k, m;
		
		n = nextInt();
		long[] arrn = new long[n];
		for (int i = 0; i < arrn.length; i++) {
			arrn[i] = nextLong();
		}
		
		k = nextInt();
		long[] arrk = new long[k];
		for (int i = 0; i < arrk.length; i++) {
			arrk[i] = nextLong();
		}
		
		m = nextInt();
		long[] arrm = new long[m];
		for (int i = 0; i < arrm.length; i++) {
			arrm[i] = nextLong();
		}
		
		List<Long> eq = new ArrayList<Long>(); 
		int i = 0,j = 0;
		while (i < n && j < k) {
			if (arrn[i] == arrk[j]) {
				eq.add(arrn[i]);
				i++;
				j++;
			} else if (arrn[i] < arrk[j]) {
				i++;
			} else {
				j++;
			}
		}
		
		int res = 0;
		i = 0;
		j = 0;
		while (i < eq.size() && j < m) {
			if (eq.get(i) == arrm[j]) {
				res++;
				i++;
				j++;
			} else if (eq.get(i) < arrm[j]) {
				i++;
			} else {
				j++;
			}
		}
		
		out.print(res);
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	
	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
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