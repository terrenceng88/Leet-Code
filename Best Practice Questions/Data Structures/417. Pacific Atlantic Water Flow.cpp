/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/


//Runs in O(m*n) time complexity using DFS and a matrix

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        vector<int> temp;
        int m = heights.size();
        if (m == 0)
            return result;
        int n = heights[0].size();
        if (n == 0)
            return result;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) { //dfs from ocean side inwards
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);

        }
        for (int j = 0; j < n; j++) { //dfs from ocean side inwards
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m-1, j);
        }

        
        for (int i = 0; i < m; i++) { //check every square in heights matrix 
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) { //add to vector if square exists both in pacific and atlantic matrix (can reach both oceans)
                    temp.clear();
                    temp.push_back(i);
                    temp.push_back(j);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();

        //recursively run DFS in every direction until the end of the matrix or a peak higher than the current one is met
        visited[i][j] = true;
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && heights[i-1][j]>=heights[i][j])
            dfs(heights, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && heights[i+1][j]>=heights[i][j])
            dfs(heights, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && heights[i][j-1]>=heights[i][j])
            dfs(heights, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && heights[i][j+1]>=heights[i][j])
            dfs(heights, visited, i, j+1);

    }
};