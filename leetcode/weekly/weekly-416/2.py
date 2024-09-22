# SOLUTION 2 TAKE LOWEST COST TO REMOVE 1 UNIT AT EVERY STEP USING MIN HEAP (PYTHON)
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        h = [(x,1,x) for x in workerTimes]
        heapq.heapify(h)
        for _ in range(mountainHeight):
            x,y,z = heapq.heappop(h)
            t = x
            heapq.heappush(h,(x+(y+1)*z,y+1,z))

        return t