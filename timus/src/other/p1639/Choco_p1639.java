package other.p1639;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Choco_p1639 implements Runnable {
	private static final String FIRST = "[:=[first]";
	private static final String SECOND = "[second]=:]";
	
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Choco_p1639()).start();
	}

	@Override
	public void run() {
		try {
			boolean oj = System.getProperty("ONLINE_JUDGE") != null;
			if (oj) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(new OutputStreamWriter(System.out));
				solve();	
			} else {
				in = new BufferedReader(new FileReader("input.txt"));
				out = new PrintWriter(new OutputStreamWriter(System.out));
				for (int i = nextInt(); i > 0; i--) {
					solve();
					out.println();
				}	
			}
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
		if (((nextInt()*nextInt() - 1) & 1) == 0)
			out.print(SECOND);
		else
			out.print(FIRST);
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