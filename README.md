# `n` by `n` grid
This program attempts to find all possible paths from the upper left corner
to the lower right corner of the grid, passing through all the squares of the grid.

# DFS and BFS
To find all the possible paths, a DFS-like search is performed to explore all the 
possible paths one by one. A BFS algorithm was not employed since there are no 
shortest paths to be found (all paths are the same length of `n^2`).

# Optimizations
The code was optimized as much as possible so that the time it take to find all
possible paths in a 7 by 7 grid is at most 2 seconds.

The optmizations applied are halving the searches and stopping when there are only
two directions to go.

# Data structures I used
To store the grid I employed a `vector` because this structure is useful to represent
the grid as a matrix and the access time of all elements is on average `O(1)`, so the
program does not spend too much time accessing items.

Additionally, I use a `pair` to store the position of columns and rows and access them
quickly.
