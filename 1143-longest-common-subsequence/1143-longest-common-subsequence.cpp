class Solution {
public:
    
    int dp[1001][1001];
    int solve(string& X, string& Y, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(X[m-1] == Y[n-1]) return dp[m][n] = 1 + solve(X, Y, m - 1, n - 1);
        else return dp[m][n] = max(solve(X, Y, m - 1, n), solve(X, Y, m, n - 1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, text1.length(), text2.length());
    }
};