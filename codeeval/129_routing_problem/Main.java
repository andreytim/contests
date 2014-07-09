import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Map;
import java.util.Set;
import java.util.HashSet;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Queue;
import java.util.List;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeSet;
import java.util.Comparator;
import java.util.Deque;

public class Main {

  public static class Graph {
    
    private final Map<Integer, Set<Integer>> adjLists = 
        new HashMap<Integer, Set<Integer>>();

    public void addEdge(Integer v1, Integer v2) {
      if (!adjLists.containsKey(v1)) {
        adjLists.put(v1, new HashSet<Integer>());
      }
      if (!adjLists.containsKey(v2)) {
        adjLists.put(v2, new HashSet<Integer>());
      }
      adjLists.get(v1).add(v2); // no duplicate check but quite suitable for this case
      adjLists.get(v2).add(v1);
    }

    public void addEdges(Integer v, Iterable<Integer> vertices) {
      for (Integer vOther : vertices) {
        if (!v.equals(vOther)) {
          addEdge(v, vOther);
        }
      }
    }

    public Set<Integer> neighbors(Integer v) {
      return adjLists.containsKey(v) ? adjLists.get(v) : Collections.<Integer>emptySet();
    }

    @Override public String toString() {
      StringBuilder builder = new StringBuilder(String.format("*** GRAPH ***\n"));
      for (Map.Entry<Integer, Set<Integer>> entry : 
              new TreeMap<Integer, Set<Integer>>(adjLists).entrySet()) {
        builder.append(String.format("%d: %s\n", entry.getKey(), entry.getValue()));
      }
      builder.append("*** ***\n");
      return builder.toString();
    }

    public int vSize() { return adjLists.size(); }
    public Set<Integer> vertices() { return adjLists.keySet(); }
    public boolean hasVertex(Integer v) { return adjLists.containsKey(v); }
  }

  public static long subnet(String cidr) {
    String[] ipAndMask = cidr.trim().split("/");
    int mask = Integer.parseInt(ipAndMask[1]);
    mask = ~((int) Math.pow(2, 32 - mask) - 1);
    int ipInt = 0;
    for (String octet : ipAndMask[0].split("\\.")) {
      ipInt = (ipInt << 8) + Integer.parseInt(octet);
    }
    return ipInt & mask;
  }

  private static final Comparator<List<Integer>> LIST_COMPARATOR = new Comparator<List<Integer>>() {
    @Override public int compare(List<Integer> l1, List<Integer> l2) {
      if (l1.size() != l2.size()) {
        return l1.size() - l2.size();
      } else {
        int i = 0;
        while (i < l1.size() && l1.get(i).equals(l2.get(i))) i++;
        if (i < l1.size()) {
          return l1.get(i) - l2.get(i);
        } else {
          return 0;
        }
      }
    }
  };  

  public static Set<List<Integer>> findPathsBfs(Graph g, Integer v1, Integer v2) {
    Queue<Integer> queue = new LinkedList<Integer>();
    Set<Integer> visited = new HashSet<Integer>();
    Map<Integer, Set<List<Integer>>> paths = new HashMap<Integer, Set<List<Integer>>>();
    paths.put(v1, new TreeSet<List<Integer>>(LIST_COMPARATOR));
    paths.get(v1).add(new ArrayList<Integer>());    
    queue.offer(v1);
    while (!queue.isEmpty()) {
      Integer curr = queue.poll();
      if (curr.equals(v2)) {
        for (List<Integer> path : paths.get(curr)) {
          path.add(v2);
        }
        return paths.get(curr);
      } else if (!visited.contains(curr)) {
        visited.add(curr);
        for (Integer v : g.neighbors(curr)) {
          if (!paths.containsKey(v)) {
            paths.put(v, new TreeSet<List<Integer>>(LIST_COMPARATOR));
          }
          for (List<Integer> path : paths.get(curr)) {
            List<Integer> newPath = new ArrayList<Integer>(path);
            newPath.add(curr);
            paths.get(v).add(newPath);
          }
          queue.offer(v);
        }
      }
    }
    return Collections.<List<Integer>>emptySet();
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String[] hosts = reader.readLine().split("\\[");
    Map<Long, List<Integer>> subnetToHosts = new HashMap<Long, List<Integer>>();
    for (int i = 0; i < hosts.length; i++) {
      if (hosts[i].indexOf("]") > 0) {
        for (String cidr : hosts[i].substring(0, hosts[i].indexOf("]")).split(", ")) {
          long sn = subnet(cidr.substring(1, cidr.length()-1));
          if (!subnetToHosts.containsKey(sn)) {
            subnetToHosts.put(sn, new ArrayList<Integer>());
          }
          subnetToHosts.get(sn).add(i-1);
        }
      }
    }
    Graph graph = new Graph();
    for (Long sn : subnetToHosts.keySet()) {
      for (Integer host : subnetToHosts.get(sn)) {
        graph.addEdges(host, subnetToHosts.get(sn));
      }
    }
    String line;    
    while ((line = reader.readLine()) != null) {
      String[] vStr = line.split(" ");
      int v1 = Integer.parseInt(vStr[0]);
      int v2 = Integer.parseInt(vStr[1]);
      if (graph.hasVertex(v1) && graph.hasVertex(v2)) {
        String result = findPathsBfs(graph, v1, v2).toString();
        result = result.substring(1, result.length() - 1);
        System.out.println(result.isEmpty() ? "No connection" : result);
      } else {
        System.out.println("No connection");
      }   
    }
  }

}
