### Module 09

#### Reverse Polish notation

* In reverse Polish notation, the operators follow their operands. For example, to add 3 and 4 together, the expression is 3 4 + rather than 3 + 4. The expression 3 − 4 + 5 in conventional notation is 3 4 − 5 + in reverse Polish notation: 4 is first subtracted from 3, then 5 is added to it.

* The concept of a stack, a last-in/first-out construct, is integral to the left-to-right evaluation of RPN. In the example 3 4 -, first the 3 is put onto the stack, then the 4; the 4 is now on top and the 3 below it. The subtraction operator removes the top two items from the stack, performs 3 - 4, and puts the result of -1 onto the stack.

* The common terminology is that added items are pushed on the stack and removed items are popped.

* The advantage of reverse Polish notation is that it removes the need for order of operations and parentheses that are required by infix notation and can be evaluated linearly, left-to-right. For example, the infix expression (3 × 4) + (5 × 6) becomes 3 4 × 5 6 × + in reverse Polish notation.

[RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

#### Ford-Johnson algorithm

Merge-insertion sort performs the following steps, on an input X of 
n elements:[6]

1. Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair. 
3. Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
4. Insert at the start of S the element that was paired with the first and smallest element of S.
5. Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering described below. Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.

The algorithm is designed to take advantage of the fact that the binary searches used to insert elements into S are most efficient (from the point of view of worst case analysis) when the length of the subsequence that is searched is one less than a power of two. This is because, for those lengths, all outcomes of the search use the same number of comparisons as each other.[1] To choose an insertion ordering that produces these lengths, consider the sorted sequence S after step 4 of the outline above (before inserting the remaining elements), and let x, denote the ith element of this sorted sequence. 

[Merge-insertion sort](https://en.wikipedia.org/wiki/Merge-insertion_sort#CITEREFFordJohnson1959)
[Ford-Johnson merge-insertion sort](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)

[Ford Johnson algorithm](https://github.com/nerraou/Ford-Johnson-algorithm)