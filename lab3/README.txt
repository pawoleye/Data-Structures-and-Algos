All the code runs.


INSERTION SORT TIME COMPLEXITY *a,b and c are constants

Best case : T(n) = a*n + c (first degree polynomial)
Average case: T(n) = a*n^2 + b*n + c (second degree polynomial)
Worst case:  T(n) = a*n^2 + b*n + c (second degree polynomial)

These equations work as for the best case the all values are already sorted, so they only have to run through the first loop for checking the condition. While for worst  and average case, the numbers are out of order and make use of both the loops, since these loops are nested it creates a quadratic effect.For sorting numbers from 1-10, best case used the fewest amount of copy and compare operations while worst case and average case produced similar times.
Therefore the time complexity is O(n^2) for worst and average case and O(n) for best case

MERGE SORT TIME COMPLEXITY 
Best case:T(n)=2T(n/2)+n
Worst case: T(n)=2T(n/2)+n
Average case:T(n)=2T(n/2)+n
T(n)=2T(n/2)+n is the same as nlog(n)				
This makes sense as merge sort always splits the array into two halves and takes linear time to merge two halves until they are individual , even if the array is already sorted. For sorting numbers from 1-10, best case, avergae case and worst case used similar amount of copy and comparitive operators.
Therefore the time complexity is O(n log(n).

*to check for test cases for sorting number between 1-10 check IScase[1-3] (insertionSort) MScase[1-3] (mergeSort).
