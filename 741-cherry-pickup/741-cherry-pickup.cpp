class Solution {
public:
    
    int dp[51][51][51];
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid, int n){
        
        int r2 = r1 + c1 - c2; 
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
        if(r1 == n - 1 && c1 == n - 1) return grid[r1][c1];
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        
        int ans = 0;
        ans += grid[r1][c1];
        if(r1 != r2) ans += grid[r2][c2];
        
        int right_right = solve(r1, c1 + 1, c2 + 1, grid, n);
        int right_down = solve(r1, c1 + 1, c2, grid, n);
        int down_right = solve(r1 + 1, c1, c2 + 1, grid, n);
        int down_down = solve(r1 + 1, c1, c2, grid, n);
        
        ans += max(max(max(right_right, right_down), down_right), down_down);
        return dp[r1][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(0,solve(0, 0, 0, grid, grid.size())); // r1, c1, c2
    }
};