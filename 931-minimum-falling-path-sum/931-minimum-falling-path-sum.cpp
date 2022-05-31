class Solution {
public:
    
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& grid, int n){
        if(i >= n || j < 0 || j >= n) return INT_MAX;
        if(i == n - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        ans += grid[i][j];
        int temp = min(solve(i + 1, j - 1, grid, n), solve(i + 1, j, grid, n));
        temp = min(temp, solve(i + 1, j + 1, grid, n));
        ans += temp;
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            memset(dp, -1, sizeof(dp));
            res = min(res, solve(0, i, matrix, n));
        }
        return res;
    }
};