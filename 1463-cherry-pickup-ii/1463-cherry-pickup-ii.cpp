class Solution {
public:
    // similar approach as that to cherry pickup
    // instead of having the state as r1, c1, r2, c2 we can get rid of r2 as r1 and r2 will be same always
    
    int dp[70][70][70];
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid, int row, int col){
        if(r1 >= row || c1 >= col || c2 >= col || c1 < 0 || c2 < 0) return INT_MIN;
        if(c1 != c2 && r1 == row - 1) return grid[r1][c1] + grid[r1][c2];
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        
        int ans = grid[r1][c1];
        if(c1 != c2) ans += grid[r1][c2];
        
        int temp = max(solve(r1 + 1,c1 - 1,c2 - 1, grid, row, col), solve(r1 + 1,c1 - 1,c2, grid, row, col));
        temp = max(temp, solve(r1+1,c1-1,c2+1, grid, row, col));
        temp = max(temp, solve(r1+1,c1,c2-1, grid, row, col));
        temp = max(temp, solve(r1+1,c1,c2, grid, row, col));
        temp = max(temp, solve(r1+1,c1,c2+1, grid, row, col));
        temp = max(temp, solve(r1+1,c1+1,c2-1, grid, row, col));
        temp = max(temp, solve(r1+1,c1+1,c2, grid, row, col));
        temp = max(temp, solve(r1+1,c1+1,c2+1, grid, row, col));
        
        ans += temp;
        return dp[r1][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, grid[0].size() - 1, grid, grid.size(), grid[0].size());
    }
};