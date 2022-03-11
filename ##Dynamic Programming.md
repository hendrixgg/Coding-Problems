## % Definition of Dynamic Programming

Any instance where we haev a larger problem that can be decomposed into smaller instances of the same problem, all the while having an overlapping/connected structure to the problem/situation.

## % Tips

 - notice nay overlapping subproblems

 - decide what is the trivially smallest input

 - think recursively to use MEMOIZATION

 - think iteratively to use TABULATION

 - draw out examples and lay out a strategy

## % Memoization - essential ideas / steps

 1. Make it work
    - it can help to visualize the problem as a tree

    - test your code

 2. Make it efficient
    - add a memo object

    - add a base case to return memo values
    
    - store return values into the memo

## % Tabulation - essential ideas 

 - visualize the problem as a table

 - size the table based on inputs
 
 - initialize the table with default values

 - seed the trivial answer into the table

 - determine a RECURRENCE RELATION

 - iterate through the table filling 
 
 - furthur positions based on the current position / current position based on previous positions
 
