# K Closest Points to Origin

[![Python](https://img.shields.io/badge/Python-3.7+-blue.svg)](https://www.python.org/downloads/)
[![LeetCode](https://img.shields.io/badge/LeetCode-973-orange.svg)](https://leetcode.com/problems/k-closest-points-to-origin/)


# *The Problem🧩* 
**Description:**  
We are given a list of points on a 2D plane. We need to find the `k` points that are closest to the origin `(0,0)`.  
The distance between two points `(x, y)` and `(0,0)` is calculated using the Euclidean formula:  

`**distance = \sqrt{x^2 + y^2}** `

---
<img width="983" height="758" alt="image" src="https://github.com/user-attachments/assets/02b1aa0e-a014-43cc-8b8f-c166bf07f955" />

##  *Example🔹*   


##### **Input:** 
-   **points = [[1,1],[-2,-2],[3,4]], k = 2** 

**Explanation:** The distances are:
- Point `[1,1]`: √(1² + 1²) = √2 ≈ 1.41
- Point `[-2,-2]`: √((-2)² + (-2)²) = √8 ≈ 2.83
- Point `[3,4]`: √(3² + 4²) = √25 = 5.0

The 2 closest points are `[1,1]` and `[-2,-2]`.

---

## 💡 Approach

This solution uses a **sort-based approach** to find the k closest points:

1. **Calculate Distances:** For each point `[x, y]`, compute the Euclidean distance from origin using the formula: `√(x² + y²)`

2. **Store Distance-Point Pairs:** Create a list where each element contains `[distance, original_point]` to keep track of both values

3. **Sort by Distance:** Sort the entire list based on distances (first element of each pair) in ascending order

4. **Extract K Closest:** Take the first `k` points from the sorted list and extract only the coordinate part (ignore distances)

---

## *Complexity ⏳*   
 - ***time Compexity :*** $$O(nlog(n))$$

 - ***Space Compexity :*** $$O(nlog(n))$$
## *Implementation 1️⃣💻*      
```python3 []
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        liste =  []   
        for i in points :   
            liste.append([math.sqrt(i[0]**2 +  i[1]**2) , i])  
        
        sorted_liste =  sorted(liste , key=lambda item  : item[0])   
        result =  []   
        for i in  range (k)  :   
            result.append(sorted_liste[i][1])   
        return  result     

```

### *🔄 Step-by-Step Walkthrough*  

- Let's trace through the example `points = [[1,1],[-2,-2],[3,4]]`, `k = 2`:

### *Step 1️⃣: Calculate distances and create pairs*      

```py
[1,1] → distance = √(1² + 1²) = √2 ≈ 1.41 → [1.41, [1,1]]
[-2,-2] → distance = √(4 + 4) = √8 ≈ 2.83 → [2.83, [-2,-2]]
[3,4] → distance = √(9 + 16) = √25 = 5.0 → [5.0, [3,4]]

```

### *Step 2️⃣ : Sort by distance* 

```py
liste = [[1.41, [1,1]], [2.83, [-2,-2]], [5.0, [3,4]]]
```

### *Step 3️⃣: Sort by distance* 

```py
result = [[1,1], [-2,-2]]
```


## *More Efficient  Solution for Smallest K  ⛓️‍💥*     
## *Complexity ⏳*   
 - ***time Compexity :*** $$O(log(n))$$

 - ***Space Compexity :*** $$O(1)$$

## *Implementation 2️⃣💻*    

### *Python*   

```python []
import heapq
def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
    heap = []
    for point in points:
        dist = point[0]**2 + point[1]**2 
        heapq.heappush(heap, (dist, point))
    return [heapq.heappop(heap)[1] for _ in range(k)]
```
### *Java*   

```java []
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
```
### *C++*  

```c++ []
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
            return a.first > b.first;  
        };
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> heap(cmp);
        
        for (auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            heap.push({dist, p});
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        
        return result;
    }
};
```

![monkey-d-luffy-leetcode.jpg](https://assets.leetcode.com/users/images/84e058ed-3713-454f-9499-3d7f33a8371a_1756830918.59436.jpeg)




