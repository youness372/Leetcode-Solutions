## *The Problem 🤔*     

- You are given a 2D integer matrix `grid` of size `n x m`, where each element is either `0`, `1`, or `2`.

- A V-shaped diagonal segment is defined as:
- The segment starts with `1`.
- The subsequent elements follow this infinite sequence: `2, 0, 2, 0, ....`
- The segment:
  
  - Starts **along** a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
  - Continues the sequence in the same diagonal direction.
  - **Makes at most one clockwise 90-degree** turn to another diagonal direction while **maintaining** the sequence. [The Link](https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/?envType=daily-question&envId=2025-08-27)
  
  - ![length_of_longest3](https://github.com/user-attachments/assets/c990ba54-0ac6-4396-b83e-92ba1d14e7c1)
 
## *Intuition ⛓️‍💥*   

According to the problem statement, the definition of a V-shaped diagonal segment is as follows:

 - The starting element of the V-shaped diagonal segment must be `1`, and the subsequent elements must alternate according to the sequence `[2,0,2,0,⋯]`. In other words, the access sequence of elements must be `[1,2,0,2,0,⋯]`.
 - Starting from one diagonal direction (`top-left` to `bottom-right`, `bottom-right` to `top-left`, `top-right to bottom-left`, or `bottom-left to top-right`), and continuing along that same diagonal, it is allowed to make at most one clockwise
`90 ∘` turn into another diagonal direction while still maintaining the sequence pattern.

- 
## *Approach ➿*   

- Start from each cell with value `1` and perform DFS.
  
- Use `dir` to track the current direction of the path:

  - `-1` means the direction hasn't been fixed yet (we can choose any of the 4 diagonals).
  - Otherwise, it represents one of the four diagonal directions.

- Maintain a boolean `canChange` to allow only one direction change.
- At each step:
  - Move in the same direction if possible and alternate the expected value (`searchFor` toggles between `2` and `0`).
  - If a direction change is allowed, try changing to the next diagonal direction.
  - Keep track of the maximum length of a valid path.


 - There are a total of 4 diagonal directions: from the upper left to the lower right, from the upper right to the lower left, from the lower right to the upper left, and from the lower left to the upper right. The corresponding coordinate offsets are *`(1,1),(1,−1),(−1,−1),(−1,1)`*. We use subscripts *`0`* to *`3`* to represent these directions. If the current direction is d and it is rotated counterclockwise by
  *`90 ∘`*
 , then the new diagonal direction is *`(d+1)mod4`*. Careful analysis shows that once the starting position and the initial diagonal direction of a V-shaped diagonal segment are determined, the maximum possible segment length depends on the longest valid continuation from the following position. At this point, dynamic programming can be applied to compute the maximum length of a V-shaped diagonal segment starting from each point.


 - For convenience, we use a top-down memoization search. Let `dfs(x,y,direction,turn,target)` represent the maximum length of a V-shaped diagonal segment starting from position `(x,y)`, where the current diagonal direction is `direction`, the expected element value is `target`, and the current rotation state is turn. We maintain `memo` to record the maximum values of all substates, and initialize all states to `−1` for ease of calculation. Since adjacent elements must follow the V-shaped sequence pattern, we also need to verify whether the current element’s value is valid given the previous one. This is an important detail in the search.

The calculation process of `dfs(x,y,direction,turn,target)` is as follows:   

- From the previous position `(x,y)` , the next position `(nx,ny)` is computed using the offset corresponding to `direction`. We then check whether `(nx,ny)` is within bounds and whether `grid[nx][ny]` equals `target`. If it goes out of bounds or does not match the target, the path is invalid and we return `0`.

- If the path continues without rotation, the next call is `dfs(nx,ny,direction,turn,2−target)`. If the path rotates, the next call is `dfs(nx,ny,(direction+1)mod4,turn,2−target)`. The maximum length starting from `(nx,ny)` is the maximum of these two cases, plus `1`. Thus, the recurrence is:

  ####  *`dfs(x,y,direction,turn,target) = max(dfs(nx,ny,direction,turn,2 − target),dfs(nx,ny,(direction+1)mod4,turn,2−target))+1`*



- Since the target value of each element can be derived directly from its position relative to the previous element, we do not need to store the target in the memoization state. This simplifies the recurrence to:

*`dfs(x,y,direction,turn)=max(dfs(nx,ny,direction,turn),dfs(nx,ny,(direction+1)mod4,turn))+1`*

- Finally, since the starting element of any valid V-shaped diagonal segment must be `1`, we iterate through the grid, launch DFS from every position where the element equals `1`, and compute the maximum length among all V-shaped diagonal segments.


## *Complexity*   
- *`Time Complexity : `* $O(M.N)$
- *`Space Complexity : `* $O(M.N)$ 
## *Implementation*   

```py
class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        DIRS = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
        m, n = len(grid), len(grid[0])

        @cache
        def dfs(cx, cy, direction, turn, target):
            nx, ny = cx + DIRS[direction][0], cy + DIRS[direction][1]
            if nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != target:
                return 0
            turn_int = 1 if turn else 0
            max_step = dfs(nx, ny, direction, turn, 2 - target)
            if turn:
                max_step = max(
                    max_step,
                    dfs(nx, ny, (direction + 1) % 4, False, 2 - target),
                )
            return max_step + 1

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for direction in range(4):
                        res = max(res, dfs(i, j, direction, True, 2) + 1)
        return res
```
```java
class Solution {

    private static final int[][] DIRS = {
        { 1, 1 },
        { 1, -1 },
        { -1, -1 },
        { -1, 1 },
    };
    private int[][][][] memo;
    private int[][] grid;
    private int m, n;

    public int lenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.memo = new int[m][n][4][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    Arrays.fill(memo[i][j][k], -1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; direction++) {
                        res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }

    private int dfs(int cx, int cy, int direction, boolean turn, int target) {
        int nx = cx + DIRS[direction][0];
        int ny = cy + DIRS[direction][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        int turnInt = turn ? 1 : 0;
        if (memo[nx][ny][direction][turnInt] != -1) {
            return memo[nx][ny][direction][turnInt];
        }

        int maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            maxStep = Math.max(
                maxStep,
                dfs(nx, ny, (direction + 1) % 4, false, 2 - target)
            );
        }
        memo[nx][ny][direction][turnInt] = maxStep + 1;
        return maxStep + 1;
    }
}
```


### *I hope I was Helpful*  


<img width="500" height="350" alt="Hope you enjoyed this part  See what's next!" src="https://github.com/user-attachments/assets/119b350b-8d11-4631-be73-03e09f38ec09" />



