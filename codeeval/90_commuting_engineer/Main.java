import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

  private static class Graph {
    
    private static class Vertex {
      public final int idx;
      public final double lat;
      public final double lon;
      public Vertex(int idx, double lat, double lon) {
        this.idx = idx;
        this.lat = lat;
        this.lon = lon;
      }
    }

    public static final int MAX_VERT = 20;
    private final double[][] adjMatrix = new double[MAX_VERT][MAX_VERT];
    private final Set<Vertex> vertices = new HashSet<Vertex>();

    public void addVertex(int idx, double lat, double lon) {
      Vertex newV = new Vertex(idx, lat, lon);
      for (Vertex v : vertices) {
        double d = distance(newV, v);
        adjMatrix[v.idx][newV.idx] = d;
        adjMatrix[newV.idx][v.idx] = d;
      }
      vertices.add(newV);
    }

    public double routeLength(List<Integer> indices) {
      double result = 0.0;
      for (int i = 0; i < indices.size() - 1; i++) {
        result += adjMatrix[indices.get(i)][indices.get(i+1)];
      }
      return result;
    }

    public Set<Integer> vertices() {
      Set<Integer> result = new HashSet<Integer>();
      for (Vertex v : vertices) {
        result.add(v.idx);
      }
      return result;
    }

    public int size() {
      return vertices.size();
    }

    private double distance(Vertex v1, Vertex v2) {
      return distance(v1.lat, v1.lon, v2.lat, v2.lon);
    }

    private double distance(double lat1, double lon1, double lat2, double lon2) {
      double theta = lon1 - lon2;
      double dist = Math.sin(deg2rad(lat1)) * Math.sin(deg2rad(lat2)) 
                        + Math.cos(deg2rad(lat1)) * Math.cos(deg2rad(lat2)) * Math.cos(deg2rad(theta));
      dist = Math.acos(dist);
      dist = rad2deg(dist);
      dist = dist * 60 * 1.1515 * 1.609344;
      return dist;
    }
    
    private double deg2rad(double deg) {
      return (deg * Math.PI / 180.0);
    }

    private double rad2deg(double rad) {
      return (rad * 180.0 / Math.PI);
    }

  }

  private static double minLength = Double.MAX_VALUE;
  private static List<Integer> minRoute;

  private static void bruteForseTSP(List<Integer> route, boolean[] visited, Graph graph) {
    if (route.size() == graph.size()) {
      double rl = graph.routeLength(route);
      if (rl < minLength) {
        minLength = rl;
        minRoute = new ArrayList<Integer>();
        minRoute.addAll(route);
      }  
    } else {
      for (int i = 1; i < visited.length; i++) {
        if (!visited[i]) {
          route.add(i);
          visited[i] = true;
          bruteForseTSP(route, visited, graph);
          visited[i] = false;
          route.remove(route.size()-1);
        }
      }
    }
  } 

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    Graph graph = new Graph();
    while ((line = reader.readLine()) != null) {
      String[] strArr = line.split(" [|] ");
      int idx = Integer.parseInt(strArr[0].trim());
      String coordStr = strArr[1].substring(strArr[1].indexOf("(")).trim();
      String[] coords = coordStr.substring(1, coordStr.length()-1).split(", ");
      graph.addVertex(idx, Double.parseDouble(coords[0]), Double.parseDouble(coords[1]));
    }
    List<Integer> route = new ArrayList<Integer>();
    route.add(1);
    boolean[] visited = new boolean[graph.size()+1];
    visited[1] = true;
    bruteForseTSP(route, visited, graph);
    for (Integer v : minRoute) {
      System.out.println(v);
    }
  }

}
