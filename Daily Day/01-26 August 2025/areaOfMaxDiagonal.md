# *the Problem🤔*   

- You are given a `2D 0-indexed` integer array dimensions.

- For all indices `i`, `0 <= i < dimensions.length`, `dimensions[i][0] 
`represents the length and `dimensions[i][1]` represents the width of the rectangle i.

- Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.


# *Approach ⛓️‍💥*   

-  The idea is we need to take the maximum  `sqrt() ` for all  the insted lists we have.   
    - Calculate ``dimensions[i][0] *  dimensions[i][0] +  dimensions[i][1] *  dimensions[i][1]``   
    - take the greater Valeu   

#### *Example*   

```py
dimensions = [[9,3],[8,6]]   
max_sqrt  , result = 0 , 0  

i = 0   
dimensions[0][0] *  dimensions[0][0] ->  9 * 9 = 81
dimensions[0][1] *  dimensions[0][1] ->  3 * 3 = 9   
 
        res = math.sqrt(81 + 9)  =  9.487
res >  max_sqrt  -> 9.487
max_sqrt  =  res , result =  81 + 9 = 90   

--------------------------------------------------------------------
i = 1
dimensions[1][0] *  dimensions[1][0] ->  8 * 8 = 64
dimensions[1][1] *  dimensions[1][1] ->  6 * 6 = 36   
 
        res = math.sqrt(64 + 36)  = 10
res >  max_sqrt  -> 10 > 9.487
max_sqrt  =  res , result =  81 + 9 = 90   

reesult =  dimension[1][0] +  dimension[1][1] = 48  

``` 
-  and we have a case when  `max_sqrt ==  math.sqrt() ` you gonna inderstand it in the code.
# *Complexity ⌛*   

- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(1)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# *Source Code 💻*



```java []
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        double max = 0;
    int result = 0;

    for (int i = 0; i < dimensions.length; i++) {
        double res = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
        double diagonal = Math.sqrt(res);

        if (diagonal > max) {
            max = diagonal;
            result = dimensions[i][0] * dimensions[i][1];
        } else if (diagonal == max && dimensions[i][0] * dimensions[i][1] > result) {
            result = dimensions[i][0] * dimensions[i][1];
        }
    }

    return result;
    }
}
```

```python3 []
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_ = 0  
        result = 0      
        for i in  range (len(dimensions)) :   
            res =  dimensions[i][0] *  dimensions[i][0] + dimensions[i][1] *  dimensions[i][1]   
            if math.sqrt(res)  >  max_ :   
                max_ =  math.sqrt(res) 
                result  =    dimensions[i][0] *  dimensions[i][1] 
            elif  math.sqrt(res) ==  max_  and dimensions[i][0] *  dimensions[i][1] > result :   
                result =  dimensions[i][0] *  dimensions[i][1]
        return result
```


![monkey-d-luffy-leetcode.jpg](https://assets.leetcode.com/users/images/057b3092-aff4-4e2d-b12e-7a9964b2ae3f_1756201642.5477688.jpeg)
