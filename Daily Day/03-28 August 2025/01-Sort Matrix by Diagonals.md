

## *The Problem 🔬*   
- You are given an  `n x n ` square matrix of integers  `grid `. Return the matrix such that:

  - The diagonals in the **`bottom-left triangle`** (including the middle diagonal) are sorted in **`non-increasing order `** .
  - The diagonals in the **`top-right triangle`** are sorted in **`non-decreasing order`**.

## *Example 1️⃣*

  - Input: **`grid = [[1,7,3],[9,8,2],[4,5,6]]`**

  - Output: **`[[8,2,3],[9,6,7],[4,5,1]]`**

### `Explanation`   

<img width="600" height="300" alt="4052example1drawio" src="https://github.com/user-attachments/assets/c95fa499-8663-4dcf-850e-8d2dff3c26e3" />

- The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

  - `[1, 8, 6]` becomes `[8, 6, 1]`.
  - `[9, 5]` and `[4]` remain unchanged.

- The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

  - `[7, 2]` becomes `[2, 7]`.
  - `[3]` remains unchanged.
  - 
## *Example 2️⃣*

Input: **`grid = [[0,1],[1,2]]`**

Output: **`[[2,1],[1,0]]`**

### `Explanation`   

<img width="500" height="300" alt="4052example2adrawio" src="https://github.com/user-attachments/assets/87351104-5a9b-46c2-99e4-be21d50c43bb" />


 - The diagonals with a black arrow must be non-increasing,
     - so `[0, 2]` is changed to `[2, 0]`.
     -  The other diagonals are already in the correct order.


##  *The Solution ☄️*      
---   

###  *Intuition 🤔*   
- The matrix needs to be sorted along its diagonals, but with different rules depending on whether the diagonal belongs to the bottom-left triangle (including the main diagonal) or the top-right triangle.

  - Bottom-left diagonals → sort in non-increasing order.
  - Top-right diagonals → sort in non-decreasing order.
- This suggests grouping numbers by diagonals (where each diagonal can be uniquely identified by i - j) and then sorting them appropriately.


### *Approach ⛓️‍💥*   

- Each diagonal can be mapped using the key `i - j`:
  - If `i - j >= 0` → `bottom-left` → sort in descending order.
  - If `i - j < 0` → `top-right` → sort in ascending order.
- To efficiently sort while building the matrix back:
  - Use a `min-heap` (PriorityQueue) for ascending order `(top-right)`.
  - Use a `max-heap` (PriorityQueue with reverse order) for descending order `(bottom-left)`.
- Traverse the matrix once to collect elements into their corresponding priority queues.
- Traverse the matrix again, and for each cell (i, j) fetch the next element from its diagonal’s heap.
- Return the modified matrix.


### *Complexity⏳*  

  - Time complexity: $O(M∗Nlog(M∗N))$
  - Space complexity: $O(M*N)$



### *Implementation [Python]*   
```py 
class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        import  heapq    
        n , m  =  len(grid) , len(grid[0])   
        diags = {}   
        for i in  range (n)  :   
            for j in range (m) :   
                key  =  i - j   
                if key  not in  diags :   
                    diags[key] = []   
                if key < 0 :   
                    heapq.heappush(diags[key] , grid[i][j])  
                else :   
                    heapq.heappush(diags[key] , -grid[i][j])   
        for i in  range (n) :   
            for j in range (m) :   
                key = i - j   
                if key < 0 :   
                    grid[i][j]  =  heapq.heappop(diags[key])   
                else :   
                    grid[i][j]  =  -heapq.heappop(diags[key])   
        return  grid 
```
### *Implementation [java]*   
```java
import java.util.*;

class Solution {
    public int[][] sortMatrix(int[][] matrix) {
        Map<Integer, PriorityQueue<Integer>> diagonalMap = new HashMap<>();
        int rows = matrix.length, cols = matrix[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int key = i - j;
                diagonalMap.putIfAbsent(key, key < 0 ? new PriorityQueue<>() 
                                                     : new PriorityQueue<>(Collections.reverseOrder()));
                diagonalMap.get(key).offer(matrix[i][j]);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int key = i - j;
                matrix[i][j] = diagonalMap.get(key).poll();
            }
        }

        return matrix;
    }
}
```

<img width="555" height="425" alt="Hope you enjoyed this part  See what's next!" src="https://github.com/user-attachments/assets/44051638-7f06-44a4-afa2-87f1bc2e0738" />
