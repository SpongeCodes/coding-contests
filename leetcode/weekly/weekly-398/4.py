# easy iterative solution in python
class Solution:
    def waysToReachStair(self, k: int) -> int:
        res, current = 0,1 
        for j in range (31):
            if current >= k :
                extra = current - k
                res+=math.comb(j+1,extra)
            current += 1<<j
        
        return res
            