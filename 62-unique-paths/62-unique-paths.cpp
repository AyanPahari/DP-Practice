class Solution {
public:
    int dp[101][101];
    int solve(int row, int col){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = solve(row - 1, col) + solve(row, col - 1);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};