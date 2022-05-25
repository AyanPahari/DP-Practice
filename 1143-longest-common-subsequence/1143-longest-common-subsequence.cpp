class Solution {
public:
    
//     int dp[1001][1001];
//     int solve(string& X, string& Y, int m, int n){
//         if(m == 0 || n == 0) return 0;
//         if(dp[m][n] != -1) return dp[m][n];
        
//         if(X[m-1] == Y[n-1]) return dp[m][n] = 1 + solve(X, Y, m - 1, n - 1);
//         else return dp[m][n] = max(solve(X, Y, m - 1, n), solve(X, Y, m, n - 1));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp, -1, sizeof(dp));
        // return solve(text1, text2, text1.length(), text2.length());
        
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};