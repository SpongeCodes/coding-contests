LeetCode Weekly Contest 400 Editorial:

1. Iterate over array and get max prefix sum at that point
2. merge intervals and then subtract days from sum of lengths of the disjoint intervals

   - my first method was to sort on basis of start day, then end day
   - traversing sorted array, adding (startDay - lastUnseenDay)
   - if startDay is ahead or end day is ahead of lastUnseenDay update to lastUnseenday as end day + 1

   - will update with better solution - refer to LC - merge intervals

3. remove last occurrence of smallest character - use map or queue

4. Many ways to implement

   - my first was to use sparse table for range-AND and find smallest AND >= k
   - and largest AND <=k and take minimum for all indices i= 0 to n-1 with i fixed as the right hand side i.e r in [l,r]
   - using binary search
   - complexity O(N\*LOGN)

   - smarter solution (credit qiqi_impact)
   - notice that numbers <=1e9 so maximum bit set is 2^29 so create array of size 30 and find for every index leftmost
   - index where bit j is still set in cumulative AND

     will update soon...
