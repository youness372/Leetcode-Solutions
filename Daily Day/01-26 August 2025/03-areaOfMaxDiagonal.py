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
