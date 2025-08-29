# *The Problem  🔬*      
---   

Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are  *`x`* flowers in the first lane between Alice and Bob,
and *`y`* flowers in the second lane between them.

<img width="560" height="280" alt="3021" src="https://github.com/user-attachments/assets/3005c64a-e5e8-4113-aca6-012cad197ddf" />


- The game proceeds as follows:

  - Alice takes the first turn.

  - In each turn, a player must choose either one of the lane and pick one flower from that side.
  
  - At the end of the turn, if there are no flowers left at all, the current player captures their opponent and wins the game.

- Given two integers, `n` and `m`, the task is to compute the number of possible pairs `(x, y)` that satisfy the conditions:

  - Alice must win the game according to the described rules.
  - The number of flowers `x` in the first lane must be in the range `[1,n]`.
  - The number of flowers `y` in the second lane must be in the range `[1,m]`.
  - Return the number of possible pairs `(x, y)` that satisfy the conditions mentioned in the statement.



## *The Solution  🤔*
---      

- The answer is `(n*m)//2`  Why? Consider the set
  
   ####  *`U={(x,y)∣x∈[1,n]∩Z,y∈[1,m]∩Z}`*

  - The set Alice can win is in fact  **`A={(x,y)∈U∣x+y≡1(mod2)}`**   the answer is the cardinality of A. Think of the chessboard.
 
  
 
<img width="700" height="500" alt="565d0c42-7f6c-438c-a94a-79d030e756bc_1756427657 942192" src="https://github.com/user-attachments/assets/170a2673-53ab-408a-84af-0a7351cacd28" />   


## *Approach ⛓️‍💥*   

- **`(n*m)//2`**  in different languages
Add Rust solution **`(n as i64)*(m as i64)>>1`**   

## *Complexity  ⏳*   

- Time complexity: **$$O(1)$$**

- Space complexity: **$$O(n)$$**

##  *Implementation 1️⃣💻*   

##### *Java*   
```java
class Solution {
    public long flowerGame(int n, int m) {
        return (long)n*m/2;
    }
}
```
##### *C++*   
```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long)m*n/2;
    }
};
```
##### *C*   
```c
long long flowerGame(int n, int m) {
    return (long long)n*m/2;
}
```

##### *Pyhton*   
```py
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return n*m//2
```


##  *Implementation 2️⃣💻*      

##### *Pyhton*   

```py
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return  (n//2) * ((m+1)//2) + ((n+1)//2) *(m//2)
```   


<img width="555" height="425" alt="Hope you enjoyed this part  See what's next!" src="https://github.com/user-attachments/assets/253909ef-e143-4df7-80d0-ee2757167f8e" />
