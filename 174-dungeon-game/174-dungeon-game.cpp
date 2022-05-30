class Solution {
public:
    
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        
        int health = min(solve(i + 1, j, grid), solve(i, j + 1, grid));
        
        if(health == INT_MAX) health = 1;
        int res = 0;
        if(health - grid[i][j] > 0) res = health - grid[i][j];
        else res = 1;
        
        return dp[i][j] = res;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, dungeon);
    }
};