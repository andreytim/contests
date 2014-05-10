import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.NavigableSet;
import java.util.TreeSet;
import java.util.Queue;
import java.util.LinkedList;

public class Main {

  private static NavigableSet<Long> generateHeap(long K) {
    NavigableSet<Long> result = new TreeSet<Long>();
    for (long i = 0; i <= K; i++) {
      result.add(i);
    }
    return result;
  }

  private static Queue<Long> initQueue(
      long K, long a, long b, long c, long r, NavigableSet<Long> heap) {
    Queue<Long> result = new LinkedList<Long>();
    for (long i = 0; i < K; i++) {
      result.offer(a);
      heap.remove(a);
      a = (b * a + c) % r;
    }
    return result;
  }

  private static long solve(long N, long K, long a, long b, long c, long r) {
    NavigableSet<Long> heap = generateHeap(K);
    Queue<Long> queue = initQueue(K, a, b, c, r, heap);
    Long curr = heap.pollFirst();
    for (long i = K; i < N-1; i++) {
      queue.offer(curr);
      Long head = queue.poll();
      if (!queue.contains(head)) {
        heap.add(head);
      }
      curr = heap.pollFirst();
    }
    return curr;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new FileReader(args[0]));
    String line;
    while ((line = reader.readLine()) != null) {
      String[] arr = line.split(",");
      long N = Long.parseLong(arr[0]);
      long K = Long.parseLong(arr[1]);
      long a = Long.parseLong(arr[2]);
      long b = Long.parseLong(arr[3]);
      long c = Long.parseLong(arr[4]);
      long r = Long.parseLong(arr[5]);
      System.out.println(solve(N, K, a, b, c, r));
    }
  }

}
