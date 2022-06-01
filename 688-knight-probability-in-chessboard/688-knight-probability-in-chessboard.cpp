class Solution {
public:
    
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    double solve(int row, int col, int n, int k, vector<vector<vector<double>>> &dp){
        if(row >= n || col >= n || row < 0 || col < 0) return 0;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        if(k == 0) return 1;
        
        double ans = 0;
        for(int i=0;i<8;i++) ans += solve(row + dx[i], col + dy[i], n, k - 1, dp)/8.0;
        return dp[row][col][k] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double>(k + 1, -1)));
        return solve(row, column, n, k, dp);
    }
};