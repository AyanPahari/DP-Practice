class Solution {
public:
    
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int row, int col){
        if(row >= grid.size()  || col >= grid[0].size()) return INT_MAX;
        if(row == grid.size() - 1 && col == grid[0].size() - 1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        return dp[row][col] = grid[row][col] + min(solve(grid, row + 1, col), solve(grid, row, col + 1));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid, 0, 0);
    }
};