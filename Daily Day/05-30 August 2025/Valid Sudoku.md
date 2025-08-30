## *The problem*   

 - Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

  - Each row must contain the digits `1-9` without repetition.
  - Each column must contain the digits `1-9` without repetition.
  - Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.
    
  **`Note`**

  - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
  - Only the filled cells need to be validated according to the mentioned rules.

##### *Example 1*   

<img width="250" height="250" alt="Sudoku-by-L2G-20050714 svg" src="https://github.com/user-attachments/assets/c2e68c14-4014-4aa6-9ac2-197f852c16c2" />   

##### *Input*   
```py
board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```
##### *Output*      
  - `true`

##### *Example 2*   

##### *Input*   
```py
board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```
##### *Output*      
  - `false`

##### *Explanation*  
 Same as Example 1, except with the **5** in the top left corner being modified to **8**. Since there are two 8's in the top left 3x3 sub-box, it is invalid.




## *Ths Solution ⛓️‍💥*  

## 📌 Problem Statement  
Given a `9 x 9` Sudoku board, determine if it is valid.  
A Sudoku board is valid if:  
- Each row contains the digits `1-9` without repetition.  
- Each column contains the digits `1-9` without repetition.  
- Each of the nine `3x3` sub-boxes contains the digits `1-9` without repetition.  

Note: The board may be partially filled, where empty cells are represented by `"."`.  

---   


## 💡 Approach  
- We need to check **3 constraints simultaneously**:  
  1. No duplicate numbers in each row.  
  2. No duplicate numbers in each column.  
  3. No duplicate numbers in each `3x3` sub-grid.  

- To do this efficiently, we use **hash sets**:  
  - `rows[i]` → stores the numbers found in row `i`.  
  - `cols[j]` → stores the numbers found in column `j`.  
  - `boxes[(i//3, j//3)]` → stores the numbers found in the sub-box corresponding to cell `(i, j)`.  

- While scanning the board cell by cell:  
  - If the cell is `"."`, skip it.  
  - If the number already exists in `rows[i]`, `cols[j]`, or its sub-box → return `False`.  
  - Otherwise, add it to the corresponding sets.  

- If no conflicts are found, return `True`.  

--- 
## *Complexity ⏳*   

- *Time Complexity :* $$O(1)$$
- *Space Complexity :* $$O(1)$$


## 📝 Code Implementation (Python)    

### *Java*    
---

```java []
import java.util.HashSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character>[] rows = new HashSet[9];
        HashSet<Character>[] cols = new HashSet[9];
        HashSet<Character>[] boxes = new HashSet[9];
        
        for (int i = 0; i < 9; i++) {
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                if (rows[i].contains(c) || cols[j].contains(c) || boxes[boxIndex].contains(c)) {
                    return false;
                }
                
                rows[i].add(c);
                cols[j].add(c);
                boxes[boxIndex].add(c);
            }
        }
        
        return true;
    }
}


```
### *Python*  
---

```python []
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows =  defaultdict(set)   
        cols =  defaultdict(set)   
        boxes =  defaultdict(set)    
          
        for i in  range (9)  :   
            for j  in  range (9)  :   
                if board[i][j]  == "."  :   
                    continue    
                
                if board[i][j] in  rows[i]  or board[i][j]   in  cols[j]  or board[i][j]  in  boxes[(i // 3  , j // 3)]  :   
                    return  False    
                rows[i].add(board[i][j])  
                cols[j].add(board[i][j])   
                boxes[(i // 3  , j  // 3)].add(board[i][j] )    
        return  True                

                
```
### *C++*   
---
```cpp []
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c)) {
                    return false;
                }
                
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        
        return true;
    }
};

```

![monkey-d-luffy-leetcode](https://github.com/user-attachments/assets/dcc21cfc-0a89-4f7c-a5b9-8dc71aa04a9c)

