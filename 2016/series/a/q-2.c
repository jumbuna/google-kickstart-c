/*

There's an island in the sea. The island can be described as a matrix with R rows and C columns, with H[i][j] indicating the height of each unit cell. Following is an example of a 3*3 island:
3 5 5
5 4 5
5 5 5
Sometimes, a heavy rain falls evenly on every cell of this island. You can assume that an arbitrarily large amount of water falls. After such a heavy rain, some areas of the island (formed of one or more unit cells joined along edges) might collect water. This can only happen if, wherever a cell in that area shares an edge (not just a corner) with a cell outside of that area, the cell outside of that area has a larger height. (The surrounding sea counts as an infinite grid of cells with height 0.) Otherwise, water will always flow away into one or more of the neighboring areas (for our purposes, it doesn't matter which) and eventually out to sea. You may assume that the height of the sea never changes. We will use W[i][j] to denote the heights of the island's cells after a heavy rain. Here are the heights of the example island after a heavy rain. The cell with initial height 4 only borders cells with higher initial heights, so water will collect in it, raising its height to 5. After that, there are no more areas surrounded by higher cells, so no more water will collect. Again, note that water cannot flow directly between cells that intersect only at their corners; water must flow along shared edges.
Following is the height of the example island after rain:
3 5 5
5 5 5
5 5 5
Given the matrix of the island, can you calculate the total increased height sum(W[i][j]-H[i][j]) after a heavy rain?

Input
The first line of the input gives the number of test cases, T. T test cases follow.
The first line of each test case contains two numbers R and C indicating the number of rows and columns of cells on the island. Then, there are R lines of C positive integers each. The j-th value on the i-th of these lines gives H[i][j]: the height of the cell in the i-th row and the j-th column.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total increased height.

Limits
1 ≤ T ≤ 100.
Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ H[i][j] ≤ 1000.

Small dataset (Test set 1 - Visible)
1 ≤ R ≤ 10.
1 ≤ C ≤ 10.

Large dataset (Test set 2 - Hidden)
1 ≤ R ≤ 50.
1 ≤ C ≤ 50.

Sample

Input
 	
Output
 
3
3 3
3 5 5
5 4 5
5 5 5
4 4
5 5 5 1
5 1 1 5
5 1 5 5
5 2 5 8
4 3
2 2 2
2 1 2
2 1 2
2 1 2

  
Case #1: 1
Case #2: 3
Case #3: 0

  
Case 1 is explained in the statement.

In case 2, the island looks like this after the rain:
5 5 5 1
5 2 2 5
5 2 5 5
5 2 5 8

Case 3 remains unchanged after the rain.

*/