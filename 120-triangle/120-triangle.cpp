class Solution {
public:
    
    int dp[201][201];
    int solve(int r, int c, vector<vector<int>>& grid, int n){
        if(r >= n) return INT_MAX;
        if(r == n - 1) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        
        int ans = INT_MAX;
        ans = min(ans, min(solve(r + 1, c + 1, grid, n), solve(r + 1, c, grid, n)));
        return dp[r][c] = ans + grid[r][c];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, triangle, n);
    }
};