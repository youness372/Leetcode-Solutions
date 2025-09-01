
## *Problem Description 🤔*   

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (1 <= k < nums.length) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`, *or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

### *Example 1️⃣*
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### *Example 2️⃣*
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

### *Example 3️⃣*
```
Input: nums = [1], target = 0
Output: -1
```

## *Solution Approach: Modified Binary Search 🔍*
---

### 🎯 Core Strategy

The key insight is that **at least one half of the rotated array is always properly sorted**. We can use this property to determine which half contains our target and eliminate the other half.

## *Algorithm Breakdown ⛓️‍💥*
---

1. **Standard Binary Search Setup**: Initialize `left = 0` and `right = len(nums) - 1`

2. **Check if Found**: If `nums[mid] == target`, return the index

3. **Determine Which Half is Sorted**:
   - If `nums[mid] >= nums[left]`: **Left half is sorted**
   - Otherwise: **Right half is sorted**

4. **Search in the Correct Half**:
   - If the sorted half contains the target → search there
   - Otherwise → search in the unsorted half

## *Code Implementation 💻*
---

### *Python Implementation*   

```python
class Solution(object):
    def search(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] >= nums[left]:
                if nums[left] <= target <= nums[mid]:
                    right = mid - 1
                else: 
                    left = mid + 1
            
            else:
                if nums[mid] <= target <= nums[right]:
                    left = mid + 1
                else:  
                    right = mid - 1
        return -1
```

### *Java Implementation*   
```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0  ;   
        int right =  nums.length -  1 ;   
        while (left <=  right)  {      
            int mid =  (right + left) / 2  ;  
            if (nums[mid] == target)  {   
                return  mid ; 
            }   
            else if (nums[mid] >= nums[left])  {   
                if (nums[left] <= target &&  target <=  nums[mid])  {   
                    right =  mid -  1 ;   
                }   
                else {   
                    left = mid +  1 ;   
                }
            }   
            else {   
                if(nums[mid] <=  target &&  target <=  nums[right])  {   
                    left = mid +  1 ;  
                }   
                else {
                    right = mid -  1 ;  
                }
            }
        }   

        return  -1 ;  
        
    }
}
```  
##  *C++  Implementation*   
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {   
        int left  = 0  ;       
        int right =  nums.size() -  1 ;   

        while (left <=  right)  {   
            int mid =  (left + right)   / 2   ;   
            if (nums[mid] == target)  {   
                return  mid ;   
            }      
            else if (nums[mid] >=  nums[left]  )  {   
                if (nums[left] <=  target &&  target  <=  nums[mid])  {   
                    right = mid -  1 ;   
                }   
                else {   
                    left  =   mid + 1 ;   
                }
            }   
            else {   
                if (nums[mid] <=  target &&  target <=  nums[right])  {   
                    left = mid +  1 ;   
                }   
                else {   
                    right = mid -  1;  
                }
            }
        }   
        return  -1 ;      
    }
};
```

## *Step-by-Step Walkthrough ⚔️*

Let's trace through `nums = [4,5,6,7,0,1,2]`, `target = 0`:

| Iteration | left | right | mid | nums[mid] | Sorted Half | Target Range Check | Action |
|-----------|------|-------|-----|-----------|-------------|-------------------|--------|
| 1 | 0 | 6 | 3 | 7 | Left (7 ≥ 4) | 0 ∉ [4,7] | left = 4 |
| 2 | 4 | 6 | 5 | 1 | Right (1 < 0) | 0 ∈ [1,2] | left = 6 |
| 3 | 6 | 6 | 6 | 2 | Left (2 ≥ 2) | 0 ∉ [2,2] | left = 7 |
| Exit | left > right, return -1... Wait! |

**Correction**: Let me trace this more carefully:

| Iteration | left | right | mid | nums[mid] | nums[left] | Comparison | Target in Range? | Action |
|-----------|------|-------|-----|-----------|------------|------------|-----------------|---------|
| 1 | 0 | 6 | 3 | 7 | 4 | 7 ≥ 4 (left sorted) | 0 ∉ [4,7] | left = 4 |
| 2 | 4 | 6 | 5 | 1 | 0 | 1 ≥ 0 (left sorted) | 0 ∈ [0,1] | right = 4 |
| 3 | 4 | 4 | 4 | 0 | 0 | nums[4] == 0 | **Found!** | return 4 |

## Visual Understanding

```
Original: [0, 1, 2, 4, 5, 6, 7]
Rotated:  [4, 5, 6, 7, 0, 1, 2]
           ^           ^
         Left half   Right half
        (sorted)    (sorted)
```

At any mid point, one side is guaranteed to be in proper sorted order!

## Time and Space Complexity

- **Time Complexity**: `O(log n)` - We eliminate half the search space each iteration
- **Space Complexity**: `O(1)` - Only using constant extra variables

## Key Insights & Edge Cases

### 🧠 Critical Insights

1. **Why `nums[mid] >= nums[left]`?**
   - Handles the case where `left == mid` (single element comparison)
   - Correctly identifies when left half is sorted

2. **Range Checking Logic**:
   - For sorted left half: `nums[left] <= target <= nums[mid]`
   - For sorted right half: `nums[mid] <= target <= nums[right]`

3. **Loop Condition**: We use `left <= right` because we're searching for an exact match

### 🔍 Edge Cases Handled

- **Single element array**: `[1]` → Works correctly
- **No rotation**: `[1,2,3,4,5]` → Standard binary search
- **Complete rotation**: `[2,3,4,5,1]` → Handles both halves
- **Target not found**: Returns `-1` as required

## Alternative Approaches

### Approach 1: Find Pivot + Binary Search
```python
def search(self, nums, target):
    pivot = self.findPivot(nums)

```

### Approach 2: Linear Search `O(n)`
```python
def search(self, nums, target):
    try:
        return nums.index(target)
    except ValueError:
        return -1
```

## Why This Solution Rocks 🚀

- ✅ **Optimal Time**: Achieves required `O(log n)` complexity
- ✅ **Space Efficient**: Uses only `O(1)` extra space  
- ✅ **Single Pass**: No need to find pivot separately
- ✅ **Clean Logic**: Clear decision tree for each case
- ✅ **Edge Case Safe**: Handles all corner cases correctly

## Related Problems

- [LeetCode 153: Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- [LeetCode 81: Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) (with duplicates)
- [LeetCode 162: Find Peak Element](https://leetcode.com/problems/find-peak-element/)

## Pro Tips 💡

1. **Remember**: At least one half is always sorted in a rotated array
2. **Debug Tip**: Print out which half is sorted at each step
3. **Interview Tip**: Explain the "one half sorted" insight upfront

---

![monkey-d-luffy-leetcode](https://github.com/user-attachments/assets/17ed1c8c-6a1f-49c3-961e-c0c25a71bb33)
