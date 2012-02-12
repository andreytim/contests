package beginner.p1001;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Sqrt_1001 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public static void main(String... args) {
		new Thread(new Sqrt_1001()).start();
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
			if (out != null)
			{
				out.flush();
				out.close();	
			}
		}
	}

	private void solve() throws IOException {
		List<String> longs = new ArrayList<String>();
		String n = nextString();
		while (n != null)
		{
			longs.add(n);
			n = nextString();
		}
		for (int i = longs.size() - 1; i >= 0; i--)
		{
			out.printf("%1$.4f", Math.sqrt(Long.parseLong(longs.get(i))));
			out.println();
		}
	}
	
	private String nextString() throws IOException {
		String token = nextToken();
		return token == null ? null : token;
	}

	private String nextToken() throws IOException 
	{
		while (st == null || !st.hasMoreTokens()) 
		{
			String line = in.readLine();
			if (line != null)
			{
				st = new StringTokenizer(line);	
			}
			else
			{
				return null;
			}
		}
		return st.nextToken();
	}
}
