LeetCode Weekly Contest 401 Editorial:

1. Iterate over array and get max prefix sum at that point
2. merge intervals and then subtract days from sum of lengths of the disjoint intervals

   - my first method was to sort on basis of start day, then end day
   - traversing sorted array, adding (startDay - lastUnseenDay)
   - if startDay is ahead or end day is ahead of lastUnseenDay update to lastUnseenday as end day + 1

   - will update with better solution - refer to LC - merge intervals

3. make observation that current sum can go upto 3999 at max with limits
   in question , i.e. length of array can be at max 2000 and values range from 1 to 2000
   so can write a simple take/not take dp and return 

4. required to optimize the quadratic dp of Q3 as problem limits increased to 5e4.

    
