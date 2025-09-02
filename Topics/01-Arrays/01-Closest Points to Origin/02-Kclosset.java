import java.util.*;

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> heap = new PriorityQueue<>(
            (a, b) -> (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1])
        );
        
        for (int[] p : points) {
            heap.add(p);
        }
        
        int[][] result = new int[k][2];
        for (int i = 0; i < k; i++) {
            result[i] = heap.poll();
        }
        
        return result;
    }
}
