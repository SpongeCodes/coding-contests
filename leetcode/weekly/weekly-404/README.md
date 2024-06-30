LeetCode Weekly Contest 400 Editorial:

1. brute force trying both cases where we start with BLUE or RED


2. 3. 
- Get maximum length of subsequence where sum modulo k of all pairwise adjacent elements is equal
My solution was to maintain dp[n][k] array where I stored:
 dp[i][j] = longest subsequence of adjacent pairwise sum = j ending at index j

 faster solution seems to fix the sum of first two elements of a subsequence and calculate max length for all pairs
 found.

 EDITORIAL SOLUTION: similar to mine but uses 1D array: will read further

4. Utilized diameter and radius of tree concepts.