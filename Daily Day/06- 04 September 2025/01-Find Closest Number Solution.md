# *Find Closest Number Solution 🐦‍🔥*   
[![LeetCode](https://img.shields.io/badge/LeetCode-3516-orange.svg)](https://leetcode.com/problems/find-closest-person/description/)

## *Problem Description 🧩*     
- Given three integers `x`, `y`, and `z`, determine which of the two numbers (`x` or `y`) is closest to `z`.
---   
### *Java Implementation*
```java
class Solution {
    public int findClosest(int x, int y, int z) {
        int a = Math.abs(z - x);
        int b = Math.abs(z - y); 
        
        if (a < b) {
            return 1; 
        }
        else if (b < a) {
            return 2; 
        }
        else {
            return 0; 
        }
    }
}
```
### *C++ Implementation*
```cpp
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z-x);   
        int b = abs(z-y)  ;    
        if ( a <b)  {  
            return  1  ;  
        }   
        else if (b < a )  {   
            return  2 ; 
        }   
        else {
            return  0  ;  
        }
    }
};
```
### *Python Implementation*
```py
class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        a =  abs(z -  x)   
        b  = abs(z - y )  
        if  a < b :   
            return  1      
        elif b < a :   
            return 2   
        else :   
            return  0  
```
## *Algorithm Explanation ⛓️‍💥*

### *Step-by-Step Process 🎯* 

- ***1️⃣ Calculate distances*** Use `Math.abs()` to find the absolute difference between `z` and both `x` and `y`.
- ***2️⃣ Compare distances*** Determine which distance is smaller
- ***3️⃣ Return result***

  - `1` if `x` is closer to `z`
  - `2` if y is closer to `z`
  - `0` if both are equidistant from `z`

### *Key Concepts:*

  - **Absolute Value:** `Math.abs(z - x)` ensures we get the positive distance regardless of which number is larger
  - **Distance Comparison:** We compare the calculated distances to determine the closest number

 
## *Test Cases and Examples*   

### *Case 1️⃣ : x is closest to z*   

```java
Input: x = 5, y = 10, z = 6
Process:
- Distance from z to x: |6 - 5| = 1
- Distance from z to y: |6 - 10| = 4
- Since 1 < 4, x is closest
Output: 1
```
### *Case 2️⃣ : y is closest to z*   

```java
Input: x = 2, y = 8, z = 7
Process:
- Distance from z to x: |7 - 2| = 5
- Distance from z to y: |7 - 8| = 1
- Since 1 < 5, y is closest
Output: 2
```
### *Case 3️⃣ : Both are equidistant from z*   

```java
Input: x = 3, y = 9, z = 6
Process:
- Distance from z to x: |6 - 3| = 3
- Distance from z to y: |6 - 9| = 3
- Since 3 = 3, both are equidistant
Output: 0
```
### *Case 4️⃣ : Negative numbers*   

```java
Input: x = -5, y = 2, z = -3
Process:
- Distance from z to x: |-3 - (-5)| = |-3 + 5| = |2| = 2
- Distance from z to y: |-3 - 2| = |-5| = 5
- Since 2 < 5, x is closest
Output: 1 1
```
### *Case 5️⃣ : z equals one of the numbers*   

```java
Input: x = 10, y = 15, z = 10
Process:
- Distance from z to x: |10 - 10| = 0
- Distance from z to y: |10 - 15| = 5
- Since 0 < 5, x is closest
Output: 1
```
---   
##  *Complexity Analysis ⏳*   


  - **Time Complexity: ⏳** $$O(1)$$ - Constant time as we perform a fixed number of operations
  - **Space Complexity: ☄️** $$O(1)$$ - Constant space as we only use a few variables

##  *Edge Cases Handled*   

  - 1.**Negative Numbers:** The solution works correctly with negative inputs due to `Math.abs()`
  - 2.**Zero Values:** Handles cases where any of `x`, `y`, or `z` is zero
  - 3.**Equal Distances:** Properly returns `0` when both numbers are equidistant
  - 4.**Identical Values:** Works when `z` equals `x` or `y` (distance becomes 0)
## *Usage Examples*   

```java
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test different scenarios
        System.out.println(solution.findClosest(5, 10, 6));   // 1
        System.out.println(solution.findClosest(2, 8, 7));    // 2
        System.out.println(solution.findClosest(3, 9, 6));    // 0
        System.out.println(solution.findClosest(-5, 2, -3));  // 1
    }
}
```

### *Return Values*   

  - `1`: `x` is closest to `z`
  - `2`: `y` is closest to `z`
  - `0`: `x` and `y` are equidistant from `z`
---   
[![GitHub followers](https://img.shields.io/github/followers/YOUR_GITHUB?style=social)](https://github.com/youness372)   
[![LeetCode profile](https://img.shields.io/badge/LeetCode-Profile-orange)](https://leetcode.com/youness-444)   


 
<img width="555" height="333" alt="Hope you enjoyed this part  See what's next!" src="https://github.com/user-attachments/assets/17bdddfe-0f3b-4c06-ae9d-fa73354cfcf3" />
