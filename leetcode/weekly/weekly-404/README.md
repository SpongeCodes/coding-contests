LeetCode Weekly Contest 404 Editorial:

1. brute force trying both cases where we start with BLUE or RED<br/>




2 AND 3 . \
Get maximum length of subsequence where sum modulo k of all pairwise adjacent elements is equal.

--
My solution was to maintain dp[n][k] array where I stored:
 dp[i][j] = longest subsequence of adjacent pairwise sum = j ending at index j

 faster solution seems to fix the sum of first two elements of a subsequence and calculate max length for all pairs
 found.

 -- TO ADD

 EDITORIAL SOLUTION: similar to mine but uses 1D array: will read further

4. Utilized diameter and radius of tree concepts.
    - Find the central point of the diameter of each tree (which will minimize the diameter of joined graph)
    - take minimum of diameter of tree 1, tree 2 , and diameter formed in step 1
    - radius (or half of diameter) can simply be calculated as ceil(diameter/2)
