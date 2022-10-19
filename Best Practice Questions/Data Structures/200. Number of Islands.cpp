/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
vertically. You may assume all four edges of the grid are all surrounded by water.
*/

//Runs in O(V^2) time complexity

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) { //recursive helper function to run DFS
        //(base case) , if out of bounds
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) { 
            return;
        }
        
        //(base case) , if not on an island anymore
        if(grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0'; //set to 0 to erase it because it has been seen already
        
        //Perform DFS in every direction to erase every part of the island and mark it as seen
        DFS(grid, i - 1, j); //left
        DFS(grid, i + 1, j); //right
        DFS(grid, i, j - 1); //up
        DFS(grid, i, j + 1); //down
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size(); //length of x axis of grid
        int n = grid[0].size(); //length of y axis of grid
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') { //if island found
                DFS(grid, i, j); //perform DFS in every direction to erase the current island; 
                ++islands; //incrment islands seen count
                }
            }
        }
        
        return islands;
    }
};