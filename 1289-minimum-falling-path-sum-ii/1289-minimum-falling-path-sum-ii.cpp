class Solution {
public:
    
    int dp[201][201];
    int solve(int r, int c, vector<vector<int>>& grid, int n){
        if(r >= n || c < 0 || c >= n) return INT_MAX;
        if(r == n - 1) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++) if(i != c) ans = min(ans, solve(r + 1, i, grid, n));
        return dp[r][c] = ans + grid[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++) res = min(res, solve(0, i, grid, n));
        return res;
    }
};