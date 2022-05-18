class Solution {
public:
    
    int dp[101][101];
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || grid[row][col] == 1) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = solve(row - 1, col, grid) + solve(row, col - 1, grid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        memset(dp,-1,sizeof(dp));
        return solve(m-1, n-1, obstacleGrid);
    }
};