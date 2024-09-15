BIWEEKLY CONTEST 135



4. DP solution involving calculating for the (i-1)th position
   at ith position. You can maintain current column, number of
   black cells in previous to previous column and number of black cells in previous column as the state.

   However this will fail TC, so you can cleverly optimize the
   DP by removing previous_to_previous count by taking a boolean value
   i.e. if the previous_previous/current column black cell count
   is more.

   video editorial: https://www.youtube.com/watch?v=71dXkbLbQUo