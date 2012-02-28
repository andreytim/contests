package graphs.p1837;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 *	Method - TreeSet for sorting and BFS for finding distances. 
 */
public class Isenbaev_p1847 implements Runnable {
	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;
	private final String UNDEFINED = "undefined";
	private final String ISENBAEV = "Isenbaev";
	
	public static void main(String... args) {
		new Thread(new Isenbaev_p1847()).start();
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
		// read data
		int N = nextInt();
		List<String[]> teams = new ArrayList<String[]>();
		Set<String> uniqueProgersSet = new TreeSet<String>(); 
		for (int i = 0; i < N; i++) {
			String[] team = new String[3];
			for (int j = 0; j < 3; j++) {
				team[j] = nextString();
				uniqueProgersSet.add(team[j]);
			}
			teams.add(team);
		}
		
		// init adjacent lists
		Map<String, Set<String>> lists = new HashMap<String, Set<String>>();
		for (String proger : uniqueProgersSet) {
			lists.put(proger, new HashSet<String>());
		}
		
		for (String[] team : teams) {
			lists.get(team[0]).add(team[1]);
			lists.get(team[0]).add(team[2]);
			lists.get(team[1]).add(team[0]);
			lists.get(team[1]).add(team[2]);
			lists.get(team[2]).add(team[0]);
			lists.get(team[2]).add(team[1]);
		}
		
		// bfs
		Map<String, Integer> degs = new HashMap<String, Integer>();
		if (lists.containsKey(ISENBAEV)) {
			String root = ISENBAEV;
			degs.put(root, 0);
			Map<String, Integer> colors = new HashMap<String, Integer>();
			colors.put(root, 0);
			for (String v : uniqueProgersSet) {
				colors.put(v, -1);
			}
			LinkedList<String> level = new LinkedList<String>();
			level.addLast(root);
			while (level.size() != 0)
			{
				String v = level.removeFirst();
				for (String u : lists.get(v)) {
					if (colors.get(u) == -1) {
						colors.put(u, 0);
						degs.put(u, degs.get(v) + 1);
						level.addLast(u);
					}
				}
				colors.put(v, 1);
			}
		}
		
		// print answer
		for (String proger : uniqueProgersSet) {
			if (degs.containsKey(proger)) {
				out.println(proger + ' ' + degs.get(proger));	
			} else {
				out.println(proger + ' ' + UNDEFINED);
			}
		}
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private String nextString() throws IOException {
		return nextToken();
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