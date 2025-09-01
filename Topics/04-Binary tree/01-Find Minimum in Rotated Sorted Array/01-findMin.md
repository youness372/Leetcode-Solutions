
## *Problem Description 🔬*
Given the sorted rotated array `nums` of **unique** elements, return the minimum element of this array.

You must write an algorithm that runs in `O(log n)` time.

#### *Example 1️⃣*
```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

#### *Example 2️⃣*
```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] rotated 4 times.
```

## *Solution Approach: Binary Search 🔍*

### *Algorithm Explanation⛓️‍💥* 

The key insight is that in a rotated sorted array, we can use binary search to find the minimum element efficiently. Here's how:

1. **Binary Search Setup**: Initialize two pointers, `left` at index 0 and `right` at the last index.

2. **Compare Middle with Right**: At each iteration, compare the middle element with the rightmost element:
   - If `nums[mid] <= nums[right]`: The minimum is in the left half (including mid)
   - If `nums[mid] > nums[right]`: The minimum is in the right half (excluding mid)

3. **Why Compare with Right?**: 
   - In a rotated array, one half is always properly sorted
   - By comparing mid with right, we can determine which half contains the rotation point (minimum)

### *Code Implementation 💻*

### *Python Implementation*   

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if nums[mid] <= nums[right]:
                right = mid
            else:
                left = mid + 1
        return nums[left]
```
### *Java Implementation*    
```java []
class Solution {
    public int findMin(int[] nums) {   
        int left = 0  ;   
        int right =  nums.length - 1 ;   
        while (left < right )  {
            int mid =  (right + left) / 2  ;    
            if (nums[mid] <= nums[right])  {  
                right =  mid ;  
            }  
            else {   
                left = mid +  1  ;  
            }
        }  
        return  nums[left] ; 
        
    }
}

```
### *C++ Implementation*   
```cpp []
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};

```



## Step-by-Step Walkthrough

Let's trace through `nums = [4,5,6,7,0,1,2]`:

| Iteration | left | right | mid | nums[mid] | nums[right] | Comparison | Action |
|-----------|------|-------|-----|-----------|-------------|------------|--------|
| 1 | 0 | 6 | 3 | 7 | 2 | 7 > 2 | left = 4 |
| 2 | 4 | 6 | 5 | 1 | 2 | 1 ≤ 2 | right = 5 |
| 3 | 4 | 5 | 4 | 0 | 1 | 0 ≤ 1 | right = 4 |

| Exit | left == right == 4, return nums[4] = 0 |

## *Time and Space Complexity ⏳* 

- **Time Complexity**: `O(log n)` - We halve the search space in each iteration
- **Space Complexity**: `O(1)` - Only using constant extra space

## *Key Points to Remember 🔐* 

1. **Why not compare with left?**: Comparing `nums[mid]` with `nums[left]` can be ambiguous when `nums[mid] == nums[left]` in cases with duplicates.

2. **Loop condition**: We use `left < right` instead of `left <= right` because we're looking for a position, not a specific value.

3. **Return statement**: We return `nums[left]` because when the loop exits, `left == right`, pointing to the minimum element.

4. **Edge cases**: 
   - Single element array: Returns immediately
   - Non-rotated array: Algorithm still works correctly

## Alternative Approaches

### Approach 1: Linear Search `O(n)`
```python
def findMin(self, nums: List[int]) -> int:
    return min(nums)
```

### Approach 2: Find Rotation Point
```python
def findMin(self, nums: List[int]) -> int:
    for i in range(len(nums) - 1):
        if nums[i] > nums[i + 1]:
            return nums[i + 1]
    return nums[0]
```

## Why This Solution is Optimal

- ✅ Meets the `O(log n)` time requirement
- ✅ Uses `O(1)` space
- ✅ Handles all edge cases correctly
- ✅ Clean and readable code
- ✅ Efficient binary search implementation

## Related Problems

- [LeetCode 154: Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) (with duplicates)
- [LeetCode 33: Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

---

![monkey-d-luffy-leetcode.jpg](https://assets.leetcode.com/users/images/780e90b5-298c-4b07-baac-a9dc1c5eafa8_1756726657.246618.jpeg)
