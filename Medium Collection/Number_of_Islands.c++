/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.


*/


class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool vis[301][301] = {0};
    int n, m;

    bool valid(int x, int y, vector<vector<char>>& grid) {
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y]);
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny, grid)) {
                dfs(nx, ny, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        n = grid.size();
        m = grid[0].size();  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid);
                    cnt++; 
                }
            }
        }
        return cnt;
    }
};


