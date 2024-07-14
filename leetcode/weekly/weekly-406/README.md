LeetCode Weekly Contest 406 Editorial:

1. Find first index where numbers are of same parity and second is smaller then swap and return


2. Simple linked list question create a dummy node and if value of
current is in set then set prev->next to curr->next.
else set prev to the current node, i.e . prev->next (very elegant)

3 and 4.

Can be solved with dp fo Q3 but constraints require something better.   Greedy intuition is that at least one cut
   of each of horizontal values and vertical values must be made
   We take the maximum at each point to minimize the cost of increased number of cuts we have to make in alternate direction

   i.e making a horizontal cut will increase the number of vertical cuts after it by one and vice-versa,

   so use two pointers and take max at each point and keep track of horizontal/vertical cuts made 